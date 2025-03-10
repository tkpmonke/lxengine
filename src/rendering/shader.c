#include "rendering/shader.h"

shader_pair_list shader_tree = {
   .data = NULL,
   .size = 0,
   .capacity = 0
};

shader* get_shader(string s) {
   for (unsigned int i = 0; i < shader_tree.size; ++i) {
      //((void(*)())s.data)();
      int cmp = strcmp(s.data, shader_tree.data[i].path.data);
      if (cmp == 0) {
         return &shader_tree.data[i].shader;
      }
   }

   return NULL;
}

void add_shader(string s, shader shader) {
   shader_pair sp = {
      .path = s,
      .shader = shader
   };

   shader_pair_list_push_back(&shader_tree, &sp);
}
