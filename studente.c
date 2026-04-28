#include <stdio.h>
#include <stdlib.h>
#include "studente.h"

struct studente{
    char *matricola;
    char **nc;
    char *CDL;
};

void registra_studente(studente *s, int pos){
    s[pos].matricola = malloc(sizeof(char*)*10);
    s[pos].nc = malloc(sizeof(char*)*2);
    s[pos].nc[0] = malloc(sizeof(char)*20);
    s[pos].nc[1] = malloc(sizeof(char)*20);
    s[pos].CDL = malloc(sizeof(char*)*15);
    printf("Nome: ");
    scanf("%s", s[pos].nc[0]);
    printf("Cognome: ");
    scanf("%s", s[pos].nc[1]);
    printf("Matricola: ");
    scanf("%s", s[pos].matricola);
    printf("CDL: ");
    scanf("%s", s[pos].CDL);
    return;
}