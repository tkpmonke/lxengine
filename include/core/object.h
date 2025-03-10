#pragma once

#include "utils/types.h"
#include "core/component.h"

typedef struct {
   string name;
   string tag;
   lxuint id;

   component_list components;
} object;
MAKE_LIST(object);

component* get_component(object*, string);
void add_component(object*, component*);
