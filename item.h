// file item.h

typedef int item;
#define NULLITEM 0

/* per semplicità il nostro tipo item è l’insieme degli interi */

int eq(item x, item y);
void input_item(item *x);
void output_item(item x);
