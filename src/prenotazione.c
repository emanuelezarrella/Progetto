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


Prenotazione *crea_posto(Studente *s, Prenotazione *p, const char *matricola){
    Studente *stud = cerca_studente(s, matricola);
    if (!stud) {
        printf("Studente non trovato.\n");
        return NULL;
    }
    else if(strcmp(stud->matricola, matricola) == 0) { //per sicurezza
        memcpy(p->matricola, matricola, sizeof(p->matricola)); // copia con memcpy in prenotazione la matricola dello studente trovato
    }
    int giorno, mese, anno = 1;
    int orario = 1;
    if(!verifica_data(&giorno, &mese, &anno)) { // verifica se la data è valida e la assegna a giorno, mese e anno
        printf("Data non valida.\n");
        return NULL;
    }
    if(!verifica_orario(&orario)) { // verifica se l'orario è valido e lo assegna a orario
        printf("Orario non valido.\n");
        return NULL;
    }
    p->data = giorno + mese * 100 + anno * 10000; // assegna la data in formato ggmmAAAA a p.data   
    p->orario = orario; // verifica se l'orario è disponibile e lo assegna a p.orario
    return p; // restituisce il puntatore alla prenotazione creata
}

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

Prenotazione *cerca_posto(Prenotazione *p, const char *matricola){
    int orario;
    printf("Immetere in che orario si vuole prenotare: \n");
    printf("1. 08:30-11:45\n");
    printf("2. 11:45-15:00\n");
    printf("3. 15:00-18:15\n");
    scanf("%d", &orario);
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
            return NULL;
    }
    while (!emptyList(cur)) {
        Prenotazione *prenotazione = (Prenotazione *) getFirst(cur);
        if (prenotazione != NULL && strcmp(prenotazione->matricola, matricola) == 0) {
            printf("Prenotazione trovata: NF%s, data: %d\n", prenotazione->matricola, prenotazione->data);
            switch(orario){
                case 1:
                printf("orario: mattina\n");
                break;
                case 2:
                printf("orario: primopomeriggio\n");
                break;
                case 3:
                printf("orario: secondopomeriggio\n");
                break;
            }
            return prenotazione;
        }
        cur = tailList(cur);
    }
    printf("Prenotazione con matricola NF%s non trovata.\n", matricola);
    return NULL;
}


void verifica_disponibilità_orario(Prenotazione *p){
    int orario;
    if (!verifica_orario(&orario)) {
        printf("Orario non valido.\n");
        return;
    }

    int giorno, mese, anno;
    int data = verifica_data(&giorno, &mese, &anno);
    if (!data) {
        printf("Data non valida.\n");
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
/*void checkin_studente(Studente *s, Prenotazione *p, list lista_mattina, list lista_primopomeriggio, list lista_secondopomeriggio){
    char matricola[MAX_MATRICOLA];
    printf("Immetere la matricola per effettuare il check-in: ");
    scanf("%8s", matricola);
    if (!cerca_posto(s, p, matricola)) {
        printf("Studente non trovato.\n");
        return;
    }
    printf("Check-in effettuato con successo, buon studio!\n");
}
*/
void visualizza_prenotazioni(list lista_mattina, list lista_primopomeriggio, list lista_secondopomeriggio){
    printf("Prenotazioni per l'orario 08:30-11:45:\n");
    outputList(lista_mattina);
    printf("Prenotazioni per l'orario 11:45-15:00:\n");
    outputList(lista_primopomeriggio);
    printf("Prenotazioni per l'orario 15:00-18:15:\n");
    outputList(lista_secondopomeriggio);
}

void inserimento_senza_prenotazione(Studente *s, const char *matricola){

    char matricola[MAX_MATRICOLA];
    printf("Inserisci la matricola dello studente da cercare: NF");
    scanf("%8s", matricola);
    cerca_studente(s, matricola);
    int orario;
    verifica_orario(orario);
    switch(orario){
        case 1:
        if(sizeList(lista_mattina) < capacità_aula){
            conslit(s->matricola, lista_mattina);
        }
        case 2:
        if(sizeList(lista_primopomeriggio) < capacità_aula){
            conslit(s->matricola, lista_primopomeriggio);
        }
        case 3:
        if(sizeList(lista_secondopomeriggio) < capacità_aula){
            conslit(s->matricola, lista_secondopomeriggio);
        }
    }
}

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