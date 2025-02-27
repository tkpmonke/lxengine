#include "core/scene.h"

scene current_scene;

void add_object_to_scene(object* obj) {
   object_list_push_back(&current_scene.objects, obj);
}
