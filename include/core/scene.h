#pragma once

#include "core/object.h"

typedef struct {
   string name;
   object_list objects;
} scene;
MAKE_LIST(scene);

void add_object_to_scene(object*);

extern scene current_scene;
