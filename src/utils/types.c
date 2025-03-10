#include "utils/types.h"

#include <string.h>
#include "utils/io.h"

string to_string(char* c) {
   int size = strlen(c);

   string s = create_char_list();
   s.size = size;

   char_list_reallocate(&s, size);
   s.data = memcpy(s.data, c, size);

   char_list_reallocate(&s, size);
   return s;
}
