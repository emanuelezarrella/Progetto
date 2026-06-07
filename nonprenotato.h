#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "list.h"
#include "prenotazione.h"

void ingresso_senza_prenotazione(Studente *s, list lista_mattina, list lista_primopomeriggio, list lista_secondopomeriggio);
void rimuovi_prenotazione(Studente *s, int matricola, list prenotazione_mattina, list prenotazione_primopomeriggio, list prenotazione_secondopomeriggio);