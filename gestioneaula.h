#include "list.h"
#include "item.h"

list attesa_mattina;
list attesa_pomeriggio1;
list attesa_pomeriggio2;

list storico_accessi;

int posti_mattina;
int posti_pomeriggio1;
int posti_pomeriggio2;

void aggiorna_posti(int *posti, int delta);

list aggiungi_attesa(list l, item matricola);

item prossimo_attesa(list *l);

list annulla_prenotazione(list l, item matricola);

void aggiungi_storico(item matricola);

void stampa_storico();

void genera_report();

int studenti_in_attesa_totale();