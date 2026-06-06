#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "list.h"
#include "studente.h"
#include "gestione_aula"

extern list lista_mattina;
extern list lista_primopomeriggio;
extern list lista_secondopomeriggio;

void verifica_disponibilità_data(int data);
void inserimento_prenotazione(Studente *s, int Matricola);
void *trova_posto(Studente *s, int matricola);
void verifica_disponibilità_orario(int orario, list lista_mattina, list lista_primopomeriggio, list lista_secondopomeriggio);
void checkin_studente(Studente *s, list lista_mattina, list lista_primopomeriggio, list lista_secondopomeriggio);
