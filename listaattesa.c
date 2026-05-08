#include <stdio.h>
#include "attesa.h"

/* inserimento in coda (FIFO) */
list aggiungi_attesa(list l, item matricola) {

    if (emptyList(l)) {
        return consList(matricola, l);
    }

    list temp = reverseList(l);

    temp = consList(matricola, temp);

    l = reverseList(temp);

    return l;
}

/* prende il primo studente in attesa */
item prossimo_attesa(list *l) {

    item matricola;

    if (emptyList(*l)) {
        return NULLITEM;
    }

    matricola = getFirst(*l);

    *l = tailList(*l);

    return matricola;
}

/* stampa lista di attesa */
void stampa_attesa(list l) {

    printf("\n--- LISTA DI ATTESA ---\n");

    while (!emptyList(l)) {

        output_item(getFirst(l));

        printf("\n");

        l = tailList(l);
    }
}