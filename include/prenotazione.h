#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "list.h"

static lista_mattina = NULL;
static lista_primopomeriggio = NULL;
static lista_secondopomeriggio = NULL;

void verifica_disponibilità_data(int data);
void inserimento_prenotazione(Studente *s, int Matricola);
void trova_posto(Studente *s, int matricola);