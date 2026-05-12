#include "item.h"
#include "list.h"

typedef struct {
    char NC;
    item matricola;
    char CDL;
} studente;

int aggiungi_posizione_studente();
void registra_studente(studente *s);
void accedi_studente(studente *s, int pos);
void verifica_disponibilità_data(item data);
void inserimento_prenotazione(studente *s);