#include "core/scene.h"

#include <stdio.h>

int main(void) {
   int_list list = create_int_list();
   
   for (int i = 0; i < 100; ++i) {
      int s = 22;
      int_list_push_back(&list, &s);

      printf("Interation %i\n", i);
      printf("Size > %i\n", list.size);
      printf("Capacity > %i\n\n", list.capacity);
   }

   printf("Printing values....\n\n");

   for (lxuint i = 0; i < list.size; ++i) {
      printf("%i, ", list.data[i]);

      if (i % 10 == 9) {
         printf("\n");
      }
   }
}
