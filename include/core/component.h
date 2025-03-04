#pragma once

#include "utils/types.h"

typedef struct {
   lxuint id;

   void (*start)();
   void (*update)(float delta);
   void (*shutdown)();

} component;
MAKE_LIST(component);

component create_component();

typedef struct {
   component* (*create_instance)();
   string name;
} component_info;
MAKE_LIST(component_info);

static struct {
   component_info_list components;
} component_registry;

void get_component_info(string name);
void register_component(component_info);
