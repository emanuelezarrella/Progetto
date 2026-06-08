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

typedef struct prenotazione{
    char matricola[MAX_MATRICOLA];
    int data;
    int orario; //1 per mattina, 2 per primo pomeriggio, 3 per secondo pomeriggio
} Prenotazione;

Prenotazione *crea_posto(Studente *s, Prenotazione *p, const char *matricola){
    Studente *s = cerca_studente(s, matricola);
    if (!s) {
        printf("Studente non trovato.\n");
        return NULL;
    }
    else if(strcmp(s->matricola, matricola) == 0) { //per sicurezza
        memcpy(p->matricola, matricola, sizeof(p->matricola)); // copia con memcpy in prenotazione la matricola dello studente trovato
    }
    p->data = verifica_data(); // verifica se la data è disponibile e lo assegna a p.data
    p->orario = verifica_orario(); // verifica se l'orario è disponibile e lo assegna a p.orario

    return p; // restituisce il puntatore alla prenotazione creata
}

void registra_prenotazione(Studente *s, Prenotazione *p){
    int matricola;
    printf("Inserisci la matricola dello studente da cercare: ");
    scanf("%6s", matricola);
    cerca_studente(s, matricola);
    crea_posto(s, p, p->matricola);
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

void cerca_posto(Studente *s, Prenotazione *p, const char *matricola){
    list cur;
    switch(p->orario) {
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
            printf("Prenotazione trovata: %s, data: %d, orario: %d\n", prenotazione->matricola, prenotazione->data, prenotazione->orario);
            return prenotazione;
        }
        cur = tailList(cur);
    }
    printf("Prenotazione con matricola %s non trovata.\n", matricola);
    return NULL;
}


void verifica_disponibilità_orario(int orario, list lista_mattina, list lista_primopomeriggio, list lista_secondopomeriggio){
    printf("Il numero di prenotazioni per la mattina è: %d\n", sizeList(lista_mattina));
    printf("Il numero di prenotazioni per il primo pomeriggio è: %d\n", sizeList(lista_primopomeriggio));
    printf("Il numero di prenotazioni per il secondo pomeriggio è: %d\n", sizeList(lista_secondopomeriggio));
}

/*void checkin_studente(Studente *s, Prenotazione *p, list lista_mattina, list lista_primopomeriggio, list lista_secondopomeriggio){
    char matricola[MAX_MATRICOLA];
    printf("Immetere la matricola per effettuare il check-in: ");
    scanf("%6s", matricola);
    if (!cerca_posto(s, p, matricola)) {
        printf("Studente non trovato.\n");
        return;
    }
    printf("Check-in effettuato con successo, buon studio!\n");
}
*/
