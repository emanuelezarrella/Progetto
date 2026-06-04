#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "list.h"
#include "studente.h"

void menu() {
    printf("\nMenu:\n");
    printf("1. Registra studente\n");
    printf("2. Prenota posto\n");
    printf("3. Verifica disponibilità orario\n");
    printf("4. Check-in prenotazioni\n");
    printf("5. Esci\n");
    printf("Scegli un'opzione: ");
}

int main(void){
    studente *s = malloc(sizeof(studente)*10);
    menu();
    int option;
    scanf("%d", &option);
    switch (option) {
        case 1: {
            registra_studente(s);
            break;
        }
        case 2: {
            int pos;
            accedi_studente(s, pos);
            inserimento_prenotazione(s);
            break;
        case 3: {
            printf("Arrivederci!");
            break;
        }
    }
    return 0;
}
}