#pragma once

#include "utils/types.h"

typedef struct {
   string real_path;
   string path;

   void* shader_data;
} shader;

typedef struct {
   string path;
   shader shader;
} shader_pair;
MAKE_LIST(shader_pair);

extern shader_pair_list shader_tree;
shader* get_shader(string);
void add_shader(string, shader);
