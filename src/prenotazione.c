#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "list.h"
#include "studente.h"
#include "prenotazione.h"
#include "utili.h"

list lista_mattina = NULL;
list lista_primopomeriggio = NULL;
list lista_secondopomeriggio = NULL;

/*
* la funzione prende in input uno studente s già esistente, prenotazione p e matricola
* controlliamo effettivamente che s esiste usando cerca_studente
* una volta verificate date e orario le inseriamo all'interno della struttura
*/
Prenotazione *crea_posto(Studente *s, Prenotazione *p, const char *matricola){
    Studente *stud = cerca_studente(s, matricola);
    if (!stud) {
        printf("Studente non trovato.\n");
        return NULL;
    }
    else if(strcmp(stud->matricola, matricola) == 0) { //per sicurezza
        memcpy(p->matricola, matricola, sizeof(p->matricola)); // copia con memcpy in prenotazione la matricola dello studente trovato
    }
    int giorno, mese, anno = 1; // per non avere conflitti con le funzioni ausialiri in utili
    int orario = 1; // stessa cosa qua
    if(!verifica_data(&giorno, &mese, &anno)) { 
        printf("Data non valida.\n");
        return NULL;
    }
    if(!verifica_orario(&orario)) { 
        printf("Orario non valido.\n");
        return NULL;
    }
    p->data = giorno + mese * 100 + anno * 10000; // assegna la data in formato ggmmAAAA a p.data   
    p->orario = orario; 
    return p;
}

/*
* funzione che prende in input studente s e prenotazione p
* controlliamo che studente s non è vuoto
* chiamiamo la funzione crea_posto
* in base all'orario che abbiamo messo in crea posto verremo inseriti in una delle 3 liste
*/
void registra_prenotazione(Studente *s, Prenotazione *p){
    char matricola[MAX_MATRICOLA];
    printf("Inserisci la matricola dello studente da cercare: NF");
    scanf("%8s", matricola);
    if (!cerca_studente(s, matricola)) {
        printf("Studente non trovato.\n");
        return;
    }
    crea_posto(s, p, matricola);
    Prenotazione *student_ptr = malloc(sizeof(Prenotazione));
    memcpy(student_ptr, p, sizeof(Prenotazione));
    switch(p->orario) {
        case 1:
            if(lista_mattina == NULL) lista_mattina = newList();
            lista_mattina = consList(student_ptr, lista_mattina);
            break;
        case 2:
            if(lista_primopomeriggio == NULL) lista_primopomeriggio = newList();
            lista_primopomeriggio = consList(student_ptr, lista_primopomeriggio);
            break;
        case 3:
            if(lista_secondopomeriggio == NULL) lista_secondopomeriggio = newList();
            lista_secondopomeriggio = consList(student_ptr, lista_secondopomeriggio);
            break;
        default:
            printf("Orario non valido\n");
            break;
    }
}

/*
* lista mattina viene passata a lista cur 
*  finché cur non è vuota allora viene presa la testa della lista 
*  viene fatto un confronto con la matricola presa in input e quella che si trova dentro la struttura
*  se le due matricole coincidono allora lo studente è trovato
*  se non coincidono si passa alla prossima lista (prima primopomeriggio poi secondopomeriggio)
*/
Prenotazione *cerca_posto(Prenotazione *p, const char *matricola){
    list cur = lista_mattina;
    while (!emptyList(cur)) {
        Prenotazione *prenotazione = (Prenotazione *) getFirst(cur);
        if (prenotazione != NULL && strcmp(prenotazione->matricola, matricola) == 0) {
            printf("Prenotazione trovata: NF%s, data: %02d/%02d/%04d\n", prenotazione->matricola, prenotazione->data % 100, (prenotazione->data / 100) % 100, prenotazione->data / 10000);
            printf("orario: mattina\n");
            return prenotazione;
        }
        cur = tailList(cur);
    }
    
   
    list cur = lista_primopomeriggio;
    while (!emptyList(cur)) {
        Prenotazione *prenotazione = (Prenotazione *) getFirst(cur);
        if (prenotazione != NULL && strcmp(prenotazione->matricola, matricola) == 0) {
            printf("Prenotazione trovata: NF%s, data: %02d/%02d/%04d\n", prenotazione->matricola, prenotazione->data % 100, (prenotazione->data / 100) % 100, prenotazione->data / 10000);
            printf("orario: primopomeriggio\n");
            return prenotazione;
        }
        cur = tailList(cur);
    }
    
    list cur = lista_secondopomeriggio;
    while (!emptyList(cur)) {
        Prenotazione *prenotazione = (Prenotazione *) getFirst(cur);
        if (prenotazione != NULL && strcmp(prenotazione->matricola, matricola) == 0) {
            printf("Prenotazione trovata: NF%s, data: %02d/%02d/%04d\n", prenotazione->matricola, prenotazione->data % 100, (prenotazione->data / 100) % 100, prenotazione->data / 10000);
            printf("orario: secondopomeriggio\n");
            return prenotazione;
        }
        cur = tailList(cur);
    }
    
    printf("Prenotazione con matricola NF%s non trovata.\n", matricola);
    return NULL;
}

/*
* Verifica il numero di prenotazioni per una data e un orario.
* Stampa la disponibilità residua o segnala l'orario pieno.
*/
void verifica_disponibilità_orario(Prenotazione *p){
    int giorno, mese, anno;
    int data = verifica_data(&giorno, &mese, &anno);
    if (!data) {
        return;
    }

    int orario;
    if (!verifica_orario(&orario)) {
        printf("Orario non valido.\n");
        return;
    }

    list cur;
    switch(orario) {
        case 1:
            cur = lista_mattina;
            break;
        case 2:
            cur = lista_primopomeriggio;
            break;
        case 3:
            cur = lista_secondopomeriggio;
            break;
        default:
            printf("Orario non valido\n");
            return;
    }

    int count = 0;
    while (!emptyList(cur)) {
        Prenotazione *prenotazione = (Prenotazione *) getFirst(cur);
        if (prenotazione != NULL && prenotazione->data == data) {
            count++;
        }
        cur = tailList(cur);
    }

    printf("Prenotazioni per %02d/%02d/%04d all'orario %d: %d\n", giorno, mese, anno, orario, count);
    if (count < 20) {
        printf("Posti disponibili: %d\n", 20 - count);
    } else {
        printf("Orario pieno, nessun posto disponibile.\n");
    }
}

/*
*  prende in input studente s, matricola e le liste delle varie fasce 
*  si sceglie quale orario liberare
*  verrà eseguito un controllo per verificare che la matricola corrisponde a quella inserita dall'utente e si libererà quel posto
*/
void libera_prenotazione(Studente *s, int matricola, list prenotazione_mattina, list prenotazione_primopomeriggio, list prenotazione_secondopomeriggio){
    printf("Immetere la matricola per rimuovere la prenotazione: NF");
    scanf("%d", &matricola);
    cerca_studente(s, matricola);
    printf("scegliere un orario per rimuovere la prenotazione: \n");
    printf("1. 08:30-11:45\n");
    printf("2. 11:45-15:00\n");
    printf("3. 15:00-18:15\n");
    int orario;
    scanf("%d", &orario);
    switch (orario) {
        case 1: {
            list cur = lista_mattina;
            for(int i = 0; !emptyList(cur); i++){
                Prenotazione *posto= (Prenotazione *) getFirst(cur);
                if (posto != NULL && posto->matricola == matricola) {
                    removeItem(prenotazione_mattina, posto);
                    break;
                }
                cur = tailList(cur);
            }
            break;
        }
        case 2: {
            list cur = lista_primopomeriggio;
            for(int i = 0; !emptyList(cur); i++){
                Prenotazione *posto = (Prenotazione *) getFirst(cur);
                if (posto != NULL && posto->matricola == matricola) {
                    removeItem(prenotazione_primopomeriggio, posto);
                    break;
                }
                cur = tailList(cur);
            }
            break;
        }
        case 3: {
            list cur = lista_secondopomeriggio;
            for(int i = 0; !emptyList(cur); i++){
                Prenotazione *posto = (Prenotazione *) getFirst(cur);
                if (posto != NULL && posto->matricola == matricola) {
                    removeItem(prenotazione_secondopomeriggio, posto);
                    break;
                }
                cur = tailList(cur);
            }
            break;
        }
    }
}

/*
* Mostra tutte le prenotazioni organizzate per fascia oraria.
*/
void visualizza_prenotazioni(list lista_mattina, list lista_primopomeriggio, list lista_secondopomeriggio){
    printf("Prenotazioni per l'orario 08:30-11:45:\n");
    outputList(lista_mattina);
    printf("Prenotazioni per l'orario 11:45-15:00:\n");
    outputList(lista_primopomeriggio);
    printf("Prenotazioni per l'orario 15:00-18:15:\n");
    outputList(lista_secondopomeriggio);
}

/*
* si tratta di una funzione simile a registra_prenotazione
* l'unica differenza è che qui c'è un controllo per verificare che la fascia oraria non sia pienamente occupata
*/
void ingresso_senza_prenotazione(Studente *s){
    char matricola[MAX_MATRICOLA];
    printf("Inserisci la matricola dello studente da cercare: NF");
    scanf("%8s", matricola);
    cerca_studente(s, matricola);
    int orario;
    verifica_orario(orario);
    switch(orario){
        case 1:
        if(sizeList(lista_mattina) < capacità_aula){
            consList(s->matricola, lista_mattina);
        }
        case 2:
        if(sizeList(lista_primopomeriggio) < capacità_aula){
            consList(s->matricola, lista_primopomeriggio);
        }
        case 3:
        if(sizeList(lista_secondopomeriggio) < capacità_aula){
            consList(s->matricola, lista_secondopomeriggio);
        }
    }
}

/*
* Cerca la prenotazione dello studente e registra il check-in.
* Controlla le tre liste e conferma il check-in se la matricola è presente.
*/
void checkin_studente(Studente *s, Prenotazione *p, list lista_mattina_arg, list lista_primopomeriggio_arg, list lista_secondopomeriggio_arg){
    char matricola[MAX_MATRICOLA];
    printf("Immetere la matricola per effettuare il check-in: NF");
    scanf("%8s", matricola);
    list curs[3] = { lista_mattina, lista_primopomeriggio, lista_secondopomeriggio };
    for (int j = 0; j < 3; j++) {
        list cur = curs[j];
        while (!emptyList(cur)) {
            Prenotazione *pren = (Prenotazione *) getFirst(cur);
            if (pren != NULL && strcmp(pren->matricola, matricola) == 0) {
                printf("Check-in effettuato per NF%s, buon studio!\n", matricola);
                return;
            }
            cur = tailList(cur);
        }
    }
    printf("Nessuna prenotazione trovata per matricola NF%s.\n", matricola);
}