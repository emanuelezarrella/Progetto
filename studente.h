#include "item.h"
#include "list.h"

typedef struct {
    item NC;
    item matricola;
    item CDL;
} studente;

void aggiungi_posizione_studente();
void registra_studente(studente *s);
void accedi_studente(studente *s, int pos);
void inserimento_prenotazione(studente *s);