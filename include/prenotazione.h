#ifndef PRENOTAZIONE_H
#define PRENOTAZIONE_H

#include "item.h"
#include "list.h"
#include "studente.h"

extern list lista_mattina;
extern list lista_primopomeriggio;
extern list lista_secondopomeriggio;
//come in studente.h

typedef struct prenotazione{
    char matricola[MAX_MATRICOLA];
    int data;
    int orario; //1 per mattina, 2 per primo pomeriggio, 3 per secondo pomeriggio
} Prenotazione;

Prenotazione *crea_posto(Studente *s, Prenotazione *p, const char *matricola);
void registra_prenotazione(Studente *s, Prenotazione *p);
void cerca_posto(Studente *s, Prenotazione *p, const char *matricola);
void verifica_disponibilità_orario(int orario, list lista_mattina, list lista_primopomeriggio, list lista_secondopomeriggio);
//void checkin_studente(Studente *s, list lista_mattina, list lista_primopomeriggio, list lista_secondopomeriggio);

#endif 
