#include <stdio.h>

#include "utils/io.h"
#include "rendering/buffer.h"

int main(void) {
   int_list list = create_int_list();
   
   for (int i = 0; i < 300; ++i) {
      int_list_push_back(&list, &i);

      /*
      printf("Interation %i\n", i);
      printf("Size > %i\n", list.size);
      printf("Capacity > %i\n\n", list.capacity);
      */
   }

   print_warning(to_string("Printing values....\n\n"));

   for (lxuint i = 0; i < list.size; ++i) {
      printf("%i, ", list.data[i]);

      if (i % 10 == 9) {
         printf("\n");
      }
   }

   int_list_free(&list);
}
