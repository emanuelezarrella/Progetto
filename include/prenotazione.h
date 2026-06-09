#ifndef PRENOTAZIONE_H
#define PRENOTAZIONE_H

#include "item.h"
#include "list.h"
#include "studente.h"

#define capacità_aula 100

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
Prenotazione *cerca_posto(Prenotazione *p, const char *matricola);
void verifica_disponibilità_orario(Prenotazione *p);
void ingresso_senza_prenotazione(Studente *s, list lista_mattina, list lista_primopomeriggio, list lista_secondopomeriggio);
void libera_prenotazione(Studente *s, int matricola, list prenotazione_mattina, list prenotazione_primopomeriggio, list prenotazione_secondopomeriggio);
void visualizza_prenotazioni(list lista_mattina, list lista_primopomeriggio, list lista_secondopomeriggio);
void inserimento_prenotazione(Studente *s, const char *matricola);
void checkin_studente(Studente *s, Prenotazione *p, list lista_mattina, list lista_primopomeriggio, list lista_secondopomeriggio);

#endif 
