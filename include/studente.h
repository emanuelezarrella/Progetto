#include "item.h"
#include "list.h"
#define MAX_STUD 67
#define MAX_CORSO 67
#define MAX_MATRICOLA 7

static list listaStudenti = NULL;

typedef struct studente{
    char nc[MAX_STUD];
    int matricola;
    char corso[MAX_CORSO];
} Studente;
// s.sin = tipi usati char
// s.sem = studente è la tipologia di dato che contiene i campi nome e cognome, matricola e corso di laurea


void registra_dati_studente(Studente *s);
void crea_studente(Studente *s);
void *cerca_studente(Studente *s,int matricola);
//void *cerca_studente(int matricola);
