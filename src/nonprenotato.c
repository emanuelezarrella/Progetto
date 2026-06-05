#include <stdio.h>
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
    printf("1. 08:30-11:45\n");
    printf("2. 11:45-15:00\n");
    printf("3. 15:00-18:15\n");
    int orario;
    scanf("%d", &orario);
    switch (orario) {
        case 1: { 
            if(sizeList(lista_mattina) < 20){
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

 void rimuovi_prenotazione(Studente *s, int matricola, list prenotazione_mattina, list prenotazione_primopomeriggio, list prenotazione_secondopomeriggio){
    printf("Immetere la matricola per rimuovere la prenotazione: ");
    scanf("%d", &matricola);
    cerca_studente(s, matricola);
    printf("scegliere un orario per rimuovere la prenotazione: \n");
    printf("1. 08:30-11:45\n");
    printf("2. 11:45-15:00\n");
    printf("3. 15:00-18:15\n");
    int orario;
    scanf("%d", &orario);
    switch (orario) {
        case 1: {
            list cur = lista_mattina;
            for(int i = 0; !emptyList(cur); i++){
                Studente *s = (Studente *) getFirst(cur);
                if (s != NULL && s->matricola == matricola) {
                    removeItem(prenotazione_mattina, s->nc);
                    break;
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
                    removeItem(prenotazione_primopomeriggio, s->nc);
                    break;
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
                    removeItem(prenotazione_secondopomeriggio, s->nc);
                    break;
                }
                cur = tailList(cur);
            }
            break;
        }
    }
}
