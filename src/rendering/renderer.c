#include "rendering/renderer.h"
#include "rendering/opengl/opengl_renderer.h"
#include "utils/io.h"

renderer main_renderer;
void set_renderer(string s) {
   if (strcmp(s.data, "OpenGL") == 0) {
      main_renderer = opengl_renderer;
   } else {
      print_fatal_error(to_string("Renderer Specified Is Not Valid"));
   }
}
