#include "rendering/opengl/opengl_renderer.h"
#include "rendering/viewport.h"

void gl_display_to_viewport() {
   glfwSwapBuffers(get_viewport()->glfw_window);
}

void gl_clear() {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   
   irect rect = get_viewport_rect();
   glViewport(0,0,rect.w,rect.h);
}

void gl_set_clear_color(vec4 color) {
   glClearColor(color[0], color[1], color[2], color[3]);
}
