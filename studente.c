#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "list.h"
#include "list.c"
#include "studente.h"


typedef struct {
    item **NC;
    item *matricola;
    item *CDL;
} studente;

int aggiungi_posizione_studente(){
    list l = newList();
    int pos;
    int i = 0;
    while(i >= 0){
        pos = i;
        if(searchItem(l, pos)){
        } 
        else {
            l = consList(pos, l);
            i = -1;
        }
    }
    return pos;
}

void registra_studente(studente *s){
    int pos = aggiungi_posizione_studente();
    s[pos].NC = malloc(sizeof(item*)*2);
    s[pos].NC[0] = malloc(sizeof(item*)*20);
    s[pos].NC[1] = malloc(sizeof(item*)*20);
    s[pos].matricola = malloc(sizeof(item*)*10);
    s[pos].CDL = malloc(sizeof(item*)*15);
    printf("Immetere il proprio NOME: ");
    scanf("%s", s[pos].NC[0]);
    printf("Immetere il proprio COGNOME: ");
    scanf("%s", s[pos].NC[1]);
    printf("Immetere la propria MATRICOLA: ");
    scanf("%s", s[pos].matricola);
    printf("Immetere il proprio Corso di Laurea: ");
    scanf("%s", s[pos].CDL);
    printf("Registrazione Effetuata con sucesso");
    printf("Benvenuto, %s %s", s[pos].NC[0], s[pos].NC[1]);
    return pos;
}
void accedi_studente(studente *s, int pos){
    char matricola[10];
    printf("Per accedere alla propria area personale, immetere la propria Matricola: ");
    scanf("%s", matricola);
    for(int i = 0; i < sizelist(s) || i > -1; i++){
        int val = i;
        if(!strcmp(s[pos].matricola, matricola)){
            printf("matricola trovata");
            printf("Benvenuto, %s %s", s[pos].NC[0], s[pos].NC[1]);
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

void inserimento_prenotazione(studente *s){
    int pos;
    accedi_studente(s, pos);
    item prenotazione;
    printf("Per procedere con l'inserimento della prenotazione, immetere nuovamente la propria Matricola: ");
    scanf("%s", s[pos].matricola);
    s[pos].NC[0] = prenotazione;
    printf("%s la tua prenotazione è stata inserita con successo", s[pos].NC[0]);
    prenotazione = newlist();
    consList(prenotazione, pos);
    printf("le abbiamo assegnato il posto %d", pos);
}