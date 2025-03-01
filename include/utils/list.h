#pragma once

/*
* TO-DO 
* - pop_back
* - clear
* - resize
* - front
* - back
* - append 
*/

#include "utils/memory.h"
#include <math.h>

#define MAKE_LIST(x) \
typedef struct { \
   unsigned int size; \
   unsigned int capacity; \
   x* data; \
} x##_list; \
\
\
\
static x##_list create_##x##_list() { \
   return (x##_list){0, 0, NULL}; \
} \
\
\
\
static void x##_list_reallocate(x##_list* list, unsigned int size) { \
   list->data = (x*)LZREALLOC(list->data, size*sizeof(x)); \
   list->capacity = size; \
} \
\
\
\
static void x##_list_push_back(x##_list* list, x* a) { \
   if (list->capacity == 0) { \
      x##_list_reallocate(list, 4); \
   } \
   if (list->size+1 > list->capacity) { \
      x##_list_reallocate(list, (int)round(list->capacity*LZLIST_ALLOCATION_STEP)); \
   } \
   list->data[list->size] = *a; \
   list->size++; \
} \
\
\
\
static void x##_list_append(x##_list* a, x##_list* b) { \
   a->size += b->size; \
   x##_list_reallocate(a, a->size); \
   memcpy(a->data+(a->size-b->size), b->data, b->size); \
} \
\
\
\
static void x##_list_free(x##_list* a) { \
   free(a->data); \
   *a = (x##_list){0,0,NULL}; \
}
