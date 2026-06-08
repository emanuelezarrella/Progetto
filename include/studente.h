#ifndef STUDENTE_H
#define STUDENTE_H

#include "item.h"
#include "list.h"
#define MAX_STUD 67
#define MAX_CORSO 67
#define MAX_MATRICOLA 7

extern list listaStudenti;
//visto che l'abbiamo dichiarata nel file c usiamo extern così non allochiamo nuova memoria

typedef struct studente{
    char nc[MAX_STUD];
    char matricola[MAX_MATRICOLA];
    char corso[MAX_CORSO];
} Studente;
// s.sin = tipi usati char
// s.sem = studente è la tipologia di dato che contiene i campi nome e cognome, matricola e corso di laurea


void registra_dati_studente(Studente *s);
void crea_studente(Studente *s);
Studente *cerca_studente(Studente *s, const char *matricola);
Studente *libera_studente(Studente *s, const char *matricola);

#endif