#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "list.h"
struct node {
 item value;
 struct node *next;
};

list newList(void){
 return NULL;
}

int emptyList(list l){
 return l == NULL;
}

list consList(item val, list l){
 struct node *nuovo;
 nuovo = malloc (sizeof(struct node));
 if (nuovo != NULL) {
 nuovo->value = val;
 nuovo->next = l;
l = nuovo;
}
 return l;
}

list tailList(list l){
 list temp;
 if (l != NULL)
temp = l->next;
 else
 temp = NULL;
 return temp;
}

item getFirst (list l) { 
item e;
 if(l != NULL)
e = l->value;
 else
 e = NULLITEM;
 return e;
}
/*progettazione: visita totale della lista, Ad ogni iterazione aggiungiamo 1 (partiamo da 0),
operazioni utilizzate: getFirst(l) per accedere al primo elemento 
tailList(l) per accedere alla parte restante della lista  */
int sizeList (list l){
 int n = 0;
 while (!emptyList(l)) // finché non raggiungiamo la fine della lista
 {
 n++; // il primo elemento contribuisce al conteggio
 l = tailList(l); // continuiamo la visita degli elementi successivi
 }
 return n;
}
/*Progettazione: visita finalizzata della lista: (usciamo da ciclo quando troviamo
l’elemento cercato oppure quando raggiungiamo la fine della lista)
usiamo una variabile booleana found che viene settata a 1 (true) quando troviamo l’elemento
*/
int posItem (list l, item val){
int pos =0; // contatore di posizione
int found =0;
while (!emptyList(l) && !found) {
if (eq(getFirst(l), val))
found =1;
else {
pos++; // incrementa il contatore di posizione
l = tailList(l); // continuiamo la visita degli elementi della lista
}
}
if(!found)
pos = -1; // se non trovato restituiamo come posizione -1
return pos;
}

item getItem (list l, int pos){
item e;
int i =0;
if (pos < 0) return NULLITEM;
// prima scorriamo la lista fino alla posizione pos … se esiste
while (i < pos && !emptyList(l)) {
i++;
l = tailList(l);
}
if (!emptyList(l)) // se la lista ha almeno pos+1 elementi
e = getFirst(l); // elemento di posizione pos
else e = NULLITEM;
return e;
}

list reverseList(list l){
 list rev; // Dichiarazione di un puntatore a una nuova lista invertita
 item val; // Dichiarazione di una variabile temporanea per memorizzare il valore degli elementi
 rev = newList(); // Inizializzazione della nuova lista vuota
 // Ciclo finché la lista originale non è vuota
 while (!emptyList(l)) {
 val = getFirst(l); // Ottiene il valore del primo elemento della lista originale
 rev = consList(val, rev); // Aggiunge il valore alla testa della lista invertita
 l = tailList(l); // Passa al prossimo elemento della lista originale
 }
 return rev; // Restituisce la lista invertita
}

int searchItem(list l, item val){
 while (!emptyList(l)) {
  if (eq(getFirst(l), val))
   return 1;
  l = tailList(l);
 }
 return 0;
}

list removeItem(list l, item val){
 list prec = NULL;
 list curr = l;
 while (!emptyList(curr)) {
  if (eq(getFirst(curr), val)) {
   if (prec == NULL) { // rimuovi testa
    l = tailList(l);
    free(curr);
    return l;
   } else {
    prec->next = curr->next;
    free(curr);
    return l;
   }
  }
  prec = curr;
  curr = tailList(curr);
 }
 return l; // non trovato
}

void outputList(list l){
 int i = 0; // Inizializzazione di un contatore per la posizione degli elementi
 item val; // Dichiarazione di una variabile temporanea per memorizzare il valore degli elementi
 // Ciclo finché la lista non è vuota
 while (!emptyList(l)) {
 val = getFirst(l); // Ottiene il valore del primo elemento della lista
 printf("Elemento di posizione %d: ", i); // Stampa la posizione dell'elemento
 output_item(val); // Stampa il valore dell'elemento utilizzando la funzione output_item() definita in item.h
 printf("\n"); // Stampa un carattere di nuova riga
 l = tailList(l); // Passa al prossimo elemento della lista
 i++; // Incrementa il contatore della posizione
 }
}

list inputList(int n){
 item val; // Dichiarazione di una variabile temporanea per memorizzare il valore degli elementi
 list l = newList(); // Creazione di una nuova lista vuota
 // Ciclo per inserire gli elementi nella lista
 for (int i = 0; i < n; i++) {
 printf("Elemento di posizione %d: ", i); // Stampa il prompt per l'inserimento dell'elemento
 input_item(&val); // Acquisisce l'elemento dall'input utilizzando la funzione input_item()
//definita in item.h
 l = consList(val, l); // Aggiunge l'elemento alla testa della lista utilizzando la funzione consList()
 }
 // Alla fine del ciclo, la lista contiene gli elementi al contrario, quindi la invertiamo
 return reverseList(l); // Restituisce la lista invertita
}
list insertList (list l, int pos, item val)
{
 item x;
 int i = 0;
 list ltmp = newList(); // lista di appoggio
 list lo = newList(); // lista di output
/* scandiamo la lista di input fino alla posizione pos e
memorizziamo i primi pos-1 elementi in una lista di appoggio ltmp */
 while (i < pos && !emptyList(l)) {
 x = getFirst(l);
 ltmp = consList(x, ltmp);
 l = tailList(l);
 i++;
 }if(i==pos) {
 lo = consList(val, l);
 while(!emptyList(ltmp)) {
 x = getFirst(ltmp);
 lo = consList(x, lo);
 ltmp = tailList(ltmp);
 }
 }
 return(lo);
}

list removeList (list l, int pos){
 list l1, prec; // puntatore al nodo da eliminare
 int i;
 if(pos == 0 && l != NULL) { // eliminazione in posizione 0
 l1 = l;
 l = tailList(l);
 free(l1);
 }
 else { // se non dobbiamo cancellare in posizione 0, scorriamo
 // la lista fino alla posizione precedente a quella del
 // nodo da eliminare
 i = 0;
 prec = l;
 while (i < pos-1 && prec!= NULL) {
 prec = prec->next;
 i++;
 }
 /* alla fine del ciclo, se prec != NULL allora prec->next punta al nodo da
eliminare. Se prec->next != NULL allora il nodo si può eliminare */
 if(prec != NULL && prec->next != NULL) { // short-circuit evaluation
 l1 = prec->next;
 prec->next = l1->next;
 free(l1);
 }
 }
 return l;
}