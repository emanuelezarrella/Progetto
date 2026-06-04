// file item.h

typedef void* item;
#define NULLITEM NULL

int eq(item x, item y);
void input_item(item *x);
void output_item(item x);
