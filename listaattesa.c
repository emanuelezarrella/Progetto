#include <stdio.h>
#include "list.h"
#include "item.h"
#include "listaattesa.h"

/* inserimento in coda*/
list aggiungi_attesa(list l, item matricola) {

    list nuovo = consList(matricola, newList());
    list tmp = l;

    if (emptyList(l)) {
        return nuovo;
    }

    while (!emptyList(tailList(tmp))) {
        tmp = tailList(tmp);
    }

    tmp->next = nuovo;

    return l;
}

/* prende il primo della lista */
item prossimo_attesa(list *l) {

    if (emptyList(*l)) {
        return NULLITEM;
    }

    item x = getFirst(*l);
    *l = tailList(*l);

    return x;
}

/* stampa lista */
void stampa_attesa(list l) {

    printf("\n--- LISTA DI ATTESA ---\n");

    while (!emptyList(l)) {

        output_item(getFirst(l));
        printf("\n");
        l = tailList(l);
    }
}
