#include "GL/glew.h"

#include "rendering/opengl/opengl_renderer.h"
#include "rendering/viewport.h"

void gl_initilize(void) {
   glfwMakeContextCurrent(get_viewport()->glfw_window);
   glewInit();
   glEnable(GL_DEPTH_TEST);
}
