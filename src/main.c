#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "list.h"
#include "studente.h"
#include "prenotazione.h"
#include "gestioneaula.h"
#include "utili.h"
/*
IMPORTANTE
PER INTERAGIRE CON IL PROGRAMMA SUL TERMINAL: 
- cd Progetto
- make clean
- make run*/
void menu() {
    printf("\nMenu:\n");
    printf("1. Registra studente\n");
    printf("2. Prenota posto\n");
    printf("3. Verifica disponibilità orario\n");
    printf("4. Cerca la tua prenotazione\n");
    printf("5: Trova_studente\n");
    printf("6: Elimina studente\n");
    printf("7. Lista attesa\n");
    printf("8. Annulla prenotazione\n");
    printf("9. Storico accessi\n");
    printf("10. Genera report\n");
    printf("11. Esci\n");
    printf("Scegli un'opzione: ");
}

int main(void){
    Studente *s = malloc(sizeof(*s));
    Prenotazione *p = malloc(sizeof(*p));
    if (s == NULL || p == NULL) {
        fprintf(stderr, "Errore di allocazione\n");
        return EXIT_FAILURE;
    }

    int option;
    while (1) {
        menu();
        if (scanf("%d", &option) != 1) {
            break;
        }

        switch (option) {
            case 1: {
                crea_studente(s);
                break;
            }
            case 2: {
                registra_prenotazione(s, p);
                break;
            }
            case 3: {
                verifica_disponibilità_orario(p);
                break;
            }
            case 4: {
                char matricola[MAX_MATRICOLA];
                printf("Inserisci la matricola dello studente da cercare: NF");
                scanf("%8s", matricola);
                cerca_posto(p, matricola);
                break;
            }
            case 5: {
                char matricola[MAX_MATRICOLA];
                printf("Inserisci la matricola dello studente da cercare: NF");
                scanf("%8s", matricola);
                cerca_studente(s, matricola);
                break;
            }
            case 6: {
                char matricola[MAX_MATRICOLA];
                printf("Immetere la matricola dello studente da eliminare: NF");
                scanf("%8s", matricola);
                libera_studente(s, matricola);
                break;
            }
            case 7: {
                int scelta;
                list cur;

                printf("Lista di attesa:\n");
                printf("1. Mattina\n");
                printf("2. Pomeriggio 1\n");
                printf("3. Pomeriggio 2\n");
                scanf("%d", &scelta);

                switch (scelta) {

                    case 1:
                        cur = attesa_mattina;
                        printf("\nAttesa mattina:\n");
                        break;

                    case 2:
                        cur = attesa_pomeriggio1;
                        printf("\nAttesa pomeriggio 1:\n");
                        break;

                    case 3:
                        cur = attesa_pomeriggio2;
                        printf("\nAttesa pomeriggio 2:\n");
                        break;

                    default:
                        printf("Scelta non valida\n");
                        continue;
                }

                while (!emptyList(cur)) {
                    output_item(getFirst(cur));
                    printf("\n");
                    cur = tailList(cur);
                }

                break;
            }

            case 8: {
                char matricola[MAX_MATRICOLA];

                printf("Inserisci matricola: ");
                scanf("%s", matricola);

                lista_mattina = annulla_prenotazione(lista_mattina, matricola);
                lista_primopomeriggio = annulla_prenotazione(lista_primopomeriggio, matricola);
                lista_secondopomeriggio = annulla_prenotazione(lista_secondopomeriggio, matricola);

                printf("Prenotazione annullata\n");
                break;
            }

            case 9: {
                stampa_storico();
                break;
            }

            case 10: {
                genera_report();
                break;
            }
            case 11: {
                printf("Arrivederci!\n");
                free(s);
                return 0;
            }
            default: {
                printf("Opzione non valida\n");
                break;
            }
        }
    }

    free(s);
    return 0;
}