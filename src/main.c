#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "list.h"
#include "studente.h"
#include "prenotazione.h"
#include "utili.h"

void menu() {
    printf("\nMenu:\n");
    printf("1. Registra studente\n");
    printf("2. Prenota posto\n");
    printf("3. Verifica disponibilità orario\n");
    printf("4. Cerca posto\n");
    printf("5: trova_studente\n");
    printf("6: Elimina studente\n");
    printf("7. Esci\n");
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