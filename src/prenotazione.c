#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "list.h"
#include "studente.h"
#include "prenotazione.h"

void verifica_disponibilità_data(int data){
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
    data = newList();
    consList(data, tempdate);
}

void *trova_posto(Studente *s, int matricola){
    if (!cerca_studente(s, matricola)) {
        printf("Studente non trovato.");
        return NULL;
    }
    int orario;
    printf("Immetere in che orario si vuole prenotare: \n");
    printf("1. 08:30-11:45\n");
    printf("2. 11:45-15:00\n");
    printf("3. 15:00-18:15\n");
    scanf("%d", &orario);
    switch (orario) {
        case 1: {
        list cur = lista_mattina;

        for(int i = 0; !emptyList(cur); i++){
        Studente *s = (Studente *) getFirst(cur);
        if (s != NULL && s->matricola == matricola) {
            printf("%s in posizione %d", s->nc, i);
            return;
        }
        cur = tailList(cur);
        }
        break;
        }
        case 2: {
        list cur = lista_primopomeriggio;

        for(int i = 0; !emptyList(cur); i++){
        Studente *s = (Studente *) getFirst(cur);
        if (s != NULL && s->matricola == matricola) {
            printf("%s in posizione %d", s->nc, i);
            return;
        }
        cur = tailList(cur);
        }
        break;
        }
        case 3: {
        list cur = lista_secondopomeriggio;

        for(int i = 0; !emptyList(cur); i++){
        Studente *s = (Studente *) getFirst(cur);
        if (s != NULL && s->matricola == matricola) {
            printf("%s in posizione %d", s->nc, i);
            return;
        }
        cur = tailList(cur);
        }
        break;
        }
    }
}

void inserimento_prenotazione(Studente *s, int matricola){
    if (!cerca_studente(s, matricola)) {
        printf("Studente non trovato.");
        return NULL;
    }
    int data;
    int option;
    verifica_disponibilità_data(data);
    printf("Immetere in che orario si vuole prenotare: \n");
    printf("1. 08:30-11:45\n");
    printf("2. 11:45-15:00\n");
    printf("3. 15:00-18:15\n");
    scanf("%d", &option);
    switch (option) {
        case 1: {
            printf("%s la tua prenotazione è stata inserita con successo", s->nc);
            if(lista_mattina == NULL) lista_mattina = newList();
            lista_mattina = consList(s->nc, lista_mattina);
            break;
        }
        case 2: {
            printf("%s la tua prenotazione è stata inserita con successo", s->nc);
            if(lista_primopomeriggio == NULL) lista_primopomeriggio = newList();
            lista_primopomeriggio = consList(s->nc, lista_primopomeriggio);
            break;
        }
        case 3: {
            printf("%s la tua prenotazione è stata inserita con successo", s->nc);
            if(lista_secondopomeriggio == NULL) lista_secondopomeriggio = newList();
            lista_secondopomeriggio = consList(s->nc, lista_secondopomeriggio);
            break;
        }
    }
}
 


void verifica_disponibilità_orario(int orario, list lista_mattina, list lista_primopomeriggio, list lista_secondopomeriggio){
    sizeList(lista_mattina);
    sizeList(lista_primopomeriggio);
    sizeList(lista_secondopomeriggio);
    printf("Il numero di prenotazioni per la mattina è: %d", sizeList(lista_mattina));
    printf("Il numero di prenotazioni per il primo pomeriggio è: %d", sizeList(lista_primopomeriggio));
    printf("Il numero di prenotazioni per il secondo pomeriggio è: %d", sizeList(lista_secondopomeriggio));
}



void checkin_studente(Studente *s, list lista_mattina, list lista_primopomeriggio, list lista_secondopomeriggio){
    int matricola;
    printf("Immetere la matricola per effettuare il check-in: ");
    scanf("%d", &matricola);
    if (!trova_posto(s, matricola)) {
        printf("Studente non trovato.");
        return NULL;
    }
    printf("Check-in effettuato con successo, buon studio!");
}
