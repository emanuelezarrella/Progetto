#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "list.h"
#include "studente.h"
#include "prenotazione.h"

list attesa_mattina = NULL;
list attesa_pomeriggio1 = NULL;
list attesa_pomeriggio2 = NULL;

list storico_accessi = NULL;

int posti_mattina = 20;
int posti_pomeriggio1 = 20;
int posti_pomeriggio2 = 20;

void aggiorna_posti(int *posti, int delta) {
    *posti = *posti + delta;
}

list aggiungi_attesa(list l, item matricola) {
    return consList(matricola, l);
}

item prossimo_attesa(list *l) {
    if (emptyList(*l)) return NULLITEM;
    item m = getFirst(*l);
    *l = tailList(*l);
    return m;
}

list annulla_prenotazione(list l, item matricola) {
    if (emptyList(l)) return l;
    if (eq(getFirst(l), matricola)) return tailList(l);

    list nuova = newList();
    list temp = l;

    while (!emptyList(temp)) {
        if (!eq(getFirst(temp), matricola)) {
            nuova = consList(getFirst(temp), nuova);
        }
        temp = tailList(temp);
    }

    return reverseList(nuova);
}

void aggiungi_storico(item matricola) {
    storico_accessi = consList(matricola, storico_accessi);
}

void stampa_storico() {
    list cur = storico_accessi;

    while (!emptyList(cur)) {
        output_item(getFirst(cur));
        cur = tailList(cur);
    }
}

void genera_report() {
    printf("Prenotazioni mattina: %d\n", sizeList(lista_mattina));
    printf("Prenotazioni pomeriggio 1: %d\n", sizeList(lista_primopomeriggio));
    printf("Prenotazioni pomeriggio 2: %d\n", sizeList(lista_secondopomeriggio));

    printf("Attesa mattina: %d\n", sizeList(attesa_mattina));
    printf("Attesa pomeriggio 1: %d\n", sizeList(attesa_pomeriggio1));
    printf("Attesa pomeriggio 2: %d\n", sizeList(attesa_pomeriggio2));

    printf("Posti mattina: %d\n", posti_mattina);
    printf("Posti pomeriggio 1: %d\n", posti_pomeriggio1);
    printf("Posti pomeriggio 2: %d\n", posti_pomeriggio2);
}

int studenti_in_attesa_totale() {
    return sizeList(attesa_mattina) +
           sizeList(attesa_pomeriggio1) +
           sizeList(attesa_pomeriggio2);
}