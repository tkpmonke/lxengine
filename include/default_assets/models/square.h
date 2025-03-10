#pragma once
#include "rendering/vertex.h"

const vertex square_vertices[] = {
   {.position = {0.5f,  0.5f, 0.0f}},
   {.position = {0.5f,  -0.5f, 0.0f}},
   {.position = {-0.5f,  -0.5f, 0.0f}},
   {.position = {-0.5f,  0.5f, 0.0f}}
};
const lxuint square_indices[] = {
   0, 1, 3,
   1, 2, 3
};
   
const mesh square_mesh = {
   .vertices = square_vertices,
   .vertex_size = 4,
   .indices = square_indices,
   .index_size = 6
};
