#include "core/component.h"

component create_component() {
   return (component) {
      .id = 0,
      .start = NULL,
      .update = NULL,
      .shutdown = NULL
   };
}
