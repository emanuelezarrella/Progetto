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

void trova_posto(Studente *s, int matricola){
    cerca_studente(s, matricola);
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
    cerca_studente(s, matricola);
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
 


void verifica_disponibilità_orario(int orario, list prenotazione_mattina, list prenotazione_primopomeriggio, list prenotazione_secondopomeriggio){
    sizeList(prenotazione_mattina);
    sizeList(prenotazione_primopomeriggio);
    sizeList(prenotazione_secondopomeriggio);
    printf("Il numero di prenotazioni per la mattina è: %d", sizeList(prenotazione_mattina));
    printf("Il numero di prenotazioni per il primo pomeriggio è: %d", sizeList(prenotazione_primopomeriggio));
    printf("Il numero di prenotazioni per il secondo pomeriggio è: %d", sizeList(prenotazione_secondopomeriggio));
}


/*
void checkin_studente(studente *s, int pos, list prenotazione_mattina, list prenotazione_primopomeriggio, list prenotazione_secondopomeriggio){
    accedi_studente(s, pos);
    for(int i = 0; i < sizeList(listaStudenti) || i > -1; i++){
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
*/