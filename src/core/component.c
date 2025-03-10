#include "core/component.h"

component create_component() {
   return (component) {
      .id = 0,
      .start = NULL,
      .update = NULL,
      .shutdown = NULL
   };
}

component_info get_component_info(string name) {
   for (lxuint i = 0; i < component_registry.components.size; ++i) {
      if (strcmp(name.data, component_registry.components.data[i].name.data) == 0) {
         return component_registry.components.data[i];
      }
   }

   return (component_info){NULL, {NULL, 0, 0}};
}
