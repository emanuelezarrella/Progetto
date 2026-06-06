#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "list.h"
#include "studente.h"
#include "prenotazione.h"
#include "gestioneaula.h"

void menu() {
    printf("\nMenu:\n");
    printf("1. Registra studente\n");
    printf("2. Prenota posto\n");
    printf("3. Verifica disponibilità orario\n");
    printf("4. Check-in prenotazioni\n");
    printf("5. Esci\n");
    printf("6. Trova studente\n");
    printf("7. Lista attesa\n");
    printf("8. Annulla prenotazione\n");
    printf("9. Storico accessi\n");
    printf("10. Genera report\n");
    printf("Scegli un'opzione: ");
}

int main(void){

    Studente *s = malloc(sizeof(Studente) * 10);

    while (1) {

        menu();

        int option;
        scanf("%d", &option);

        switch (option) {

            case 1: {
                registra_studente(s);
                break;
            }

            case 2: {
                int matricola;
                printf("Inserisci la matricola dello studente: ");
                scanf("%d", &matricola);
                inserimento_prenotazione(s, matricola);
                break;
            }

            case 3: {
                int orario;
                printf("1. 08:30-11:45\n");
                printf("2. 11:45-15:00\n");
                printf("3. 15:00-18:15\n");
                scanf("%d", &orario);

                verifica_disponibilità_orario(orario, lista_mattina, lista_primopomeriggio, lista_secondopomeriggio);
                break;
            }

            case 4: {
                checkin_studente(s, lista_mattina, lista_primopomeriggio, lista_secondopomeriggio);
                break;
            }

            case 5: {
                printf("Arrivederci!\n");
                exit(0);
            }

            case 6: {
                char matricola[MAX_MATRICOLA];
                printf("Inserisci matricola: ");
                scanf("%s", matricola);
                cerca_studente(s, matricola);
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

            default: {
                printf("Opzione non valida\n");
                break;
            }
        }
    }

    return 0;
}