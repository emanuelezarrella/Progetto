#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "list.h"
#include "studente.h"


typedef struct {
    char **NC;
    item *matricola;
    char *CDL;
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
void accedi_studente(studente *s, int pos){
    s[pos].NC = malloc(sizeof(char*)*2);
    s[pos].NC[0] = malloc(sizeof(char*)*20);
    s[pos].NC[1] = malloc(sizeof(char*)*20);
    s[pos].matricola = malloc(sizeof(item*)*10);
    s[pos].CDL = malloc(sizeof(char*)*15);
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

void registra_studente(studente *s){
    int pos = aggiungi_posizione_studente();
    printf("Immetere il proprio NOME: ");
    scanf("%s", s[pos].NC[0]);
    printf("Immetere il proprio COGNOME: ");
    scanf("%s", s[pos].NC[1]);
    printf("Immetere la propria MATRICOLA: ");
    scanf("%s", s[pos].matricola);
    printf("Immetere il proprio Corso di Laurea: ");
    scanf("%s", s[pos].CDL);
    printf("Registrazione Effetuata con sucesso");
    s[pos].NC = realloc(s[pos].NC, sizeof(char*)*40);
    s[pos].NC = strcpy(s[pos].NC, s[pos].NC[0]);
    s[pos].NC = strcat(s[pos].NC, " ");
    s[pos].NC = strcat(s[pos].NC, s[pos].NC[1]);
    printf("Benvenuto, %s %s", s[pos].NC[0], s[pos].NC[1]);
    return pos;
}