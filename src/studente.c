#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "item.h"
#include "list.h"
#include "studente.h"

static list listaStudenti = NULL;


void registra_dati_studente(Studente *s){
    printf("Immetere il proprio NOME e COGNOME: ");
    int c;
    while ((c = getchar()) != '\n' && c != EOF); //pulisce il buffer
    fgets(s->nc, sizeof(s->nc), stdin);
    printf("\nImmetere la propria MATRICOLA: NF");
    scanf("%s", &s->matricola);
    printf("\nImmetere il proprio Corso di Laurea: ");
    while ((c = getchar()) != '\n' && c != EOF); //puliamo il buffer un'altra volta
    fgets(s->corso, sizeof(s->corso), stdin);
    printf("\n");
    printf("\nRegistrazione Effetuata con successo\n");
}

void crea_studente(Studente *s){
    registra_dati_studente(s);
    Studente *student_ptr = malloc(sizeof(Studente));
    memcpy(student_ptr, s, sizeof(Studente));
    if(listaStudenti == NULL) listaStudenti = newList();
    listaStudenti = consList(student_ptr, listaStudenti);
}
//PROGETTAZIONE FUNZIONE 
// PRENDIAMO I DATI APPENA INSERITI DALL'UTENTE
//CREIAMO UN NUOVO PUNTATORE A UN'AREA DI MEMORIA CHE CONTIENE I DATI DI S
//CON MEMCPY METTIAMO I DATI DI S NELLA NUOVA AREA DI MEMORIA
//AGGIUNGIAMO IL PUNTATORE ALLA LISTA DEGLI STUDENTI
// FINE (spero)
void registra_studente(Studente *s){
    crea_studente(s);
    printf("ecco le credinziali che hai inserito: \n%s, \n%s, \n%s", s->nc, s->matricola, s->corso);
}

void *cerca_studente(Studente *s, char matricola){
    printf("%s", matricola);
    list cur = listaStudenti;
    while (!emptyList(cur)) {
        Studente *s = (Studente *) getFirst(cur);
        if (s != NULL && strcmp(s->matricola, matricola) == 0) {
            printf("Studente trovato: %s, %s\n", s->nc, s->corso);
            return s;
        }
        cur = tailList(cur);
    }
    return NULL;
}
