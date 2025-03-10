#include "rendering/renderer.h"
#include "rendering/viewport.h"
#include "rendering/opengl/opengl_renderer.h"
#include "default_assets/models/square.h"

char *vertex_shader = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "out vec3 pos;\n"
    "void main()\n"
    "{\n"
    "   pos = aPos+0.5f;\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";
char *fragment_shader = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "in vec3 pos;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(pos,1)*vec4(1.0f, 0.5f, 0.85f, 1.0f);\n"
    "}\n\0";

int main(void) {
   set_renderer(to_string("OpenGL"));

   set_viewport_name(to_string("LXEditor"));
   create_viewport();

   main_renderer.initilize();

   shader main_shader = main_renderer.create_shader(to_string(vertex_shader), to_string(fragment_shader));
   add_shader(to_string("Core/3D/Unlit"), main_shader);

   material material = {
      .shader = to_string("Core/3D/Unlit"),
      .name = to_string("Testing")
   };

   render_mesh rm = main_renderer.create_render_mesh((mesh*)&square_mesh);
   
   vec4 bg_color = {0.1,0.1,0.2,1};
   while (is_viewport_open()) {
      main_renderer.set_clear_color(bg_color);
      main_renderer.clear();

      draw_call_params params = {
         .material = &material,
         .render_mesh = &rm
      };
      main_renderer.draw(&params);
      main_renderer.display_to_viewport();
   }

   main_renderer.destroy_shader(&main_shader);
   destroy_viewport();
   return 0;
}


