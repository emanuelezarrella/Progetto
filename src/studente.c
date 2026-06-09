#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "item.h"
#include "list.h"
#include "studente.h"

list listaStudenti = NULL;

void registra_dati_studente(Studente *s){
    char matricola[MAX_MATRICOLA];
    here:
    printf("\nImmetere la propria MATRICOLA: NF");
    scanf("%8s", matricola);
    if (strlen(matricola) == 8) {
        strcpy(s->matricola, matricola);
    } else {
        printf("Errore! la matricola deve avere 8 caratteri\n");
        goto here;
    }
    printf("Immetere il proprio NOME e COGNOME: ");
    int c;
    while ((c = getchar()) != '\n' && c != EOF); // pulisce il buffer
    fgets(s->nc, sizeof(s->nc), stdin);
    printf("Immetere il proprio Corso di Laurea: ");
    fgets(s->corso, sizeof(s->corso), stdin);
    printf("\nRegistrazione Effettuata con successo\n");
}

void crea_studente(Studente *s){
    registra_dati_studente(s);
    Studente *student_ptr = malloc(sizeof(Studente));
    memcpy(student_ptr, s, sizeof(Studente));
    if(listaStudenti == NULL) listaStudenti = newList();
    if (cerca_studente(s, s->matricola) != NULL) {
        printf("Studente con matricola NF%s già registrato.\n", s->matricola);
        //free(student_ptr);
        return;
    }
    listaStudenti = consList(student_ptr, listaStudenti);
}

Studente *cerca_studente(Studente *s, const char *matricola){
    list cur = listaStudenti;
    while (!emptyList(cur)) {
        Studente *student = (Studente *) getFirst(cur);
        if (student != NULL && strcmp(student->matricola, matricola) == 0) {
            printf("Studente trovato: NF%s, %s, %s\n", student->matricola, student->nc, student->corso);
            return student;
        }
        cur = tailList(cur);
    }
    printf("Studente con matricola NF%s non trovato.\n", matricola);
    return NULL;
}

Studente *libera_studente(Studente *s, const char *matricola){

    list cur = listaStudenti;
    while (!emptyList(cur)) {
        Studente *student = (Studente *) getFirst(cur);
        if (student != NULL && strcmp(student->matricola, matricola) == 0) {
            removeItem(cur, student);
            printf("Studente con matricola NF%s eliminato.\n", matricola);
            return student;
        }
        cur = tailList(cur);
    }
    printf("Studente con matricola NF%s non trovato.\n", matricola);
    return NULL;
}
