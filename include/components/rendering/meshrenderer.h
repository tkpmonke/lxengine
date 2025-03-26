#include "core/component.h"
#include "rendering/renderer.h"

typedef struct {
   component* base;

   mesh* mesh;
   material material;
} meshrenderer;

void meshrenderer_start();
void meshrenderer_update();
void meshrenderer_on_destroy();
