#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "list.h"
#include "studente.h"
#include "prenotazione.h"

void menu() {
    printf("\nMenu:\n");
    printf("1. Registra studente\n");
    printf("2. Prenota posto\n");
    printf("3. Verifica disponibilità orario\n");
    printf("4. Check-in prenotazioni\n");
    printf("6: trova_studente\n");
    printf("7: Elimina studente\n");
    printf("5. Esci\n");
    printf("Scegli un'opzione: ");
}

int main(void){
    Studente *s = malloc(sizeof(*s));
    if (s == NULL) {
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
                char matricola[MAX_MATRICOLA];
                printf("Inserisci la matricola dello studente da cercare: ");
                scanf("%6s", matricola);
                inserimento_prenotazione(s, matricola);
                break;
            }
            case 3: {
                printf("immetere l'orario da verificare: \n");
                printf("1. 08:30-11:45\n");
                printf("2. 11:45-15:00\n");
                printf("3. 15:00-18:15\n");
                int orario;
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
                free(s);
                return 0;
            }
            case 6: {
                char matricola[MAX_MATRICOLA];
                printf("Inserisci la matricola dello studente da cercare: ");
                scanf("%6s", matricola);
                cerca_studente(s, matricola);
                break;
            }
            case 7: {
                char matricola[MAX_MATRICOLA];
                printf("Immetere la matricola dello studente da eliminare: ");
                scanf("%6s", matricola);
                libera_studente(s, matricola);
                break;
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