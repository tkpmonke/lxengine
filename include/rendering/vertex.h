#pragma once

#include "utils/types.h"

typedef struct {
   vec3 position;
   vec3 normal;
   vec2 uv;
} vertex;
MAKE_LIST(vertex);

typedef struct {
   vertex* vertices;
   lxuint* indices;

   lxuint vertex_size, index_size;
} mesh;
