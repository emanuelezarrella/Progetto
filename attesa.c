#include <stdio.h>
#include "item.h"
#include "list.h"
#include "attesa.h"

void aggiungi_attesa(list *attesa, item matricola){

    *attesa = consList(matricola, *attesa);

    printf("Studente aggiunto alla lista di attesa\n");
}

void rimuovi_attesa(list *attesa, item matricola){

    if(searchItem(*attesa, matricola) == 1){

        *attesa = removeItem(*attesa, matricola);

        printf("Studente rimosso dalla lista di attesa\n");
    }

    else{

        printf("Studente non presente in lista di attesa\n");
    }
}

void visualizza_attesa(list attesa){

    if(emptyList(attesa)){

        printf("Lista di attesa vuota\n");
    }

    else{

        printf("Studenti in attesa:\n");

        outputList(attesa);
    }
}