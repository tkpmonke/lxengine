#pragma once

#include "utils/types.h"

typedef struct {
   lxuint id;
   string type;

   void (*start)(struct component* self);
   void (*update)(struct component* self, float delta);
   void (*on_destroy)(struct component* self);

} component;
MAKE_LIST(component);

typedef component* componentptr;
MAKE_LIST(componentptr);

/*
component create_component();

typedef struct {
   component* (*create_instance)();
   string name;
} component_info;
MAKE_LIST(component_info);

static struct {
   component_info_list components;
} component_registry;

component_info get_component_info(string name);
*/
