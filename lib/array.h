#ifndef ARRAY_H
#define ARRAY_H

#include "poly.h"

typedef struct Array
{
  poly *array;
  int capacity;
  int size;
} *Array_t;

Array_t Array_new ();
Array_t Array_newSize (int size);
Array_t Array_array (poly x, ...);
poly Array_nth (Array_t l, int n);
void Array_insert (Array_t l, poly x, int i);
poly Array_delete (Array_t l, int i);
int Array_isEmpty (Array_t l);
int Array_exists (Array_t l, int (*pred) (poly));
Array_t Array_map (Array_t l, poly (*f) (poly));
void Array_foreach (Array_t l, void (*f)(poly));
char *Array_toString (Array_t l, char *(*f)(poly));

#endif
