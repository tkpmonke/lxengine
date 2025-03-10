#pragma once

#include "rendering/shader.h"

typedef struct {
   string name;

   enum shader_value_type {
      shader_value_type_int,
      shader_value_type_bool,
      shader_value_type_float,
      shader_value_type_double,
      shader_value_type_vec2,
      shader_value_type_vec3,
      shader_value_type_vec4,
      shader_value_type_mat2,
      shader_value_type_mat3,
      shader_value_type_mat4
   } type;

   union {
      int v_int;
      _Bool v_bool;
      float v_float;
      double v_double;
      vec2 v_vec2;
      vec3 v_vec3;
      vec4 v_vec4;
      mat2 v_mat2;
      mat3 v_mat3;
      mat4 v_mat4;
   } value;
} shader_value;
MAKE_LIST(shader_value);

typedef struct {
   shader_value_list values;
   string shader;

   string name;
   string path;
   string real_path;
} material;
MAKE_LIST(material);

extern material_list loaded_material_list;

material* get_material(string);
void add_material(material*);

shader_value get_shader_value(material*, string);
void set_shader_value(material*, shader_value);

void compile_default_materials();
