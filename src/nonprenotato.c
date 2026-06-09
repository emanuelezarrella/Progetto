/*#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "list.h"
#include "studente.h"
#include "prenotazione.h"

void ingresso_senza_prenotazione(Studente *s, list lista_mattina, list lista_primopomeriggio, list lista_secondopomeriggio){
    int matricola;
    printf("Immetere la matricola per accedere alla biblioteca senza prenotazione: ");
    scanf("%d", &matricola);
    cerca_studente(s, matricola);
    printf("scegliere un orario per accedere alla biblioteca: \n");

                lista_mattina = consList(s->nc, lista_mattina);
            }
            else {
                printf("Siamo spiacenti, non ci sono posti disponibili in questo orario");
            }
            break;
        }
        case 2: { 
            if(sizeList(lista_primopomeriggio) < 20){
                lista_primopomeriggio = consList(s->nc, lista_primopomeriggio);
            }
            else {
                printf("Siamo spiacenti, non ci sono posti disponibili in questo orario");
            }
            break;
        }
        case 3: { 
            if(sizeList(lista_secondopomeriggio) < 20){
                lista_secondopomeriggio = consList(s->nc, lista_secondopomeriggio);
            }
            else {
                printf("Siamo spiacenti, non ci sono posti disponibili in questo orario");
            }
            break;
        }
    }
}

*/
