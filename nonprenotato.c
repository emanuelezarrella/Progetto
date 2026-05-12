#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "list.h"
#include "studente.h"

void ingresso_senza_prenotazione(list prenotazione_mattina, list prenotazione_primopomeriggio, list prenotazione_secondopomeriggio, studente *s){
    int pos;
    accedi_studente(s, pos);
    printf("Benvenuto, puoi accedere alla biblioteca senza prenotazione al primo posto disponibile");
    if(sizelist(prenotazione_mattina) < 20){
        printf("le abbiamo assegnato il posto %d", sizelist(prenotazione_mattina)+1);
    }
    else if(sizelist(prenotazione_primopomeriggio) < 20){
        printf("le abbiamo assegnato il posto %d", sizelist(prenotazione_primopomeriggio)+1);
    }
    else if(sizelist(prenotazione_secondopomeriggio) < 20){
        printf("le abbiamo assegnato il posto %d", sizelist(prenotazione_secondopomeriggio)+1);
    }
    else {
        printf("Siamo spiacenti, non ci sono posti disponibili");
    }
}

  void rimuovi_prenotazione(studente *s, list prenotazione_mattina, list prenotazione_primopomeriggio, list prenotazione_secondopomeriggio){
    int pos;
    accedi_studente(s, pos);
    for(int i = 0; i < sizelist(s) || i > -1; i++){
        int val = i;
        if(!strcmp(s[pos].NC, prenotazione_mattina) || !strcmp(s[pos].NC, prenotazione_primopomeriggio) || !strcmp(s[pos].NC, prenotazione_secondopomeriggio)){
            printf("La tua prenotazione è stata rimossa con successo");
            pos = val;
            i = -1;
        }
        else if(i > sizelist(s)){
            printf("Non hai prenotazioni attive");
        }
    }
}
