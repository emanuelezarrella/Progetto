#ifndef PRENOTAZIONE_H
#define PRENOTAZIONE_H

#include "item.h"
#include "list.h"
#include "studente.h"

extern list lista_mattina;
extern list lista_primopomeriggio;
extern list lista_secondopomeriggio;
//come in studente.h

void verifica_disponibilità_data(int data);
void inserimento_prenotazione(Studente *s, const char *matricola);
Studente *trova_posto(Studente *s, const char *matricola);
void verifica_disponibilità_orario(int orario, list lista_mattina, list lista_primopomeriggio, list lista_secondopomeriggio);
void checkin_studente(Studente *s, list lista_mattina, list lista_primopomeriggio, list lista_secondopomeriggio);

#endif /* PRENOTAZIONE_H */
