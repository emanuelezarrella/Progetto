#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "list.h"
#include "list.c"
#include "studente.h"
#include "listaattesa.h"

void verifica_disponibilità_data(item data){
    int **tempdate;
    tempdate = malloc(sizeof(int*)*2);
    tempdate[0] = malloc(sizeof(int*)*2); //giorno
    tempdate[1] = malloc(sizeof(int*)*2); //mese

    printf("Immetere la data in cui si vuole prenotare (formato gg/mm): ");
    scanf("%d/%d", &tempdate[0][0], &tempdate[1][0]);

    int datamod = (tempdate[0][1]) % 100;
    switch(datamod){     
        case 101: {
            printf("Data non disponibile, giorno festivo");
            break;
        }
        case 105: {
            printf("Data non disponibile, giorno festivo");
            break;
        }
         case 111: {
            printf("Data non disponibile, giorno festivo");
            break;
        }
        case 206: {
            printf("Data non disponibile, giorno festivo");
            break;
        }
        case 504: {
            printf("Data non disponibile, giorno festivo");
            break;
        }
         case 508: {
            printf("Data non disponibile, giorno festivo");
            break;
        }
        case 512: {
            printf("Data non disponibile, giorno festivo");
            break;
        }
        case 601: {
            printf("Data non disponibile, giorno festivo");
            break;
        }
        case 612: {
            printf("Data non disponibile, giorno festivo");
            break;
        }
        case 812: {
            printf("Data non disponibile, giorno festivo");
            break;
        }

        default: {
            printf("Data disponibile, procedere con la prenotazione");
            break;
        }
    }
    data = newlist();
    consList(data, tempdate);
}
void inserimento_prenotazione(studente *s , list *listaattesa){
    int pos;
    accedi_studente(s, &pos);
    list prenotazione_mattina;
    list prenotazione_primopomeriggio;
    list prenotazione_secondopomeriggio;
    int data;
    verifica_disponibilità_data(data);
    printf("Immetere in che orario si vuole prenotare: \n");
    printf("1. 08:30-11:45\n");
    printf("2. 11:45-15:00\n");
    printf("3. 15:00-18:15\n");
    int option;
    scanf("%d", &option);
    switch (option) {
        case 1: {
            printf("%s la tua prenotazione è stata inserita con successo", s[pos].NC);
            prenotazione_mattina = newlist();
            consList(prenotazione_mattina, s[pos].NC);
            printf("le abbiamo assegnato il posto %d", pos);
            break;
        }
        case 2: {
            printf("%s la tua prenotazione è stata inserita con successo", s[pos].NC);
            prenotazione_primopomeriggio = newlist();
            consList(prenotazione_primopomeriggio, s[pos].NC);
            printf("le abbiamo assegnato il posto %d", pos);
            break;
        }
        case 3: {
            printf("%s la tua prenotazione è stata inserita con successo", s[pos].NC);
            prenotazione_secondopomeriggio = newlist();
            consList(prenotazione_secondopomeriggio, s[pos].NC);
            printf("le abbiamo assegnato il posto %d", pos);
            break;
        }
    }
}

void verifica_disponibilità_orario(item orario, list prenotazione_mattina, list prenotazione_primopomeriggio, list prenotazione_secondopomeriggio){
    sizelist(prenotazione_mattina);
    sizelist(prenotazione_primopomeriggio);
    sizelist(prenotazione_secondopomeriggio);
    printf("Il numero di prenotazioni per la mattina è: %d", sizelist(prenotazione_mattina));
    printf("Il numero di prenotazioni per il primo pomeriggio è: %d", sizelist(prenotazione_primopomeriggio));
    printf("Il numero di prenotazioni per il secondo pomeriggio è: %d", sizelist(prenotazione_secondopomeriggio));
}

void checkin_studente(studente *s, int pos, list prenotazione_mattina, list prenotazione_primopomeriggio, list prenotazione_secondopomeriggio){
    accedi_studente(s, pos);
    for(int i = 0; i < sizelist(s) || i > -1; i++){
        int val = i;
        if(!posItem(prenotazione_mattina, s[pos].NC) || !posItem(prenotazione_primopomeriggio, s[pos].NC) || !posItem(prenotazione_secondopomeriggio, s[pos].NC)){
            printf("Check-in effettuato con successo, buon lavoro!");
            pos = val;
            i = -1;
        }
        else if(i > sizelist(s)){
            printf("Matricola non trovata, registrazione necessaria");
            registra_studente(s);
        }
        }
        return pos;
}

