#include "item.h"
#include "list.h"

typedef struct {
    char NC;
    char matricola;
    char CDL;
} studente;

int aggiungi_posizione_studente();
void registra_studente(studente *s);
void accedi_studente(studente *s, int pos);
void verifica_disponibilità_data(int data);
void inserimento_prenotazione(studente *s);