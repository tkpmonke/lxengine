#include "rendering/viewport.h"

viewport vp = {
   .rect = {
      0, 0, 1280, 720
   },
   .glfw_window = NULL
};
viewport* get_viewport() {
   return &vp;
}

void create_viewport() {
   if (!glfwInit()) {
      exit(1);
      return;
   }
   vp.glfw_window = glfwCreateWindow(vp.rect.w, vp.rect.h, vp.name.data, NULL, NULL);


   glfwSetWindowPos(vp.glfw_window, vp.rect.x, vp.rect.y);
}

void destroy_viewport() {
   glfwDestroyWindow(vp.glfw_window);
   glfwTerminate();
}

int is_viewport_open() {
   glfwPollEvents();

   glfwGetWindowPos(vp.glfw_window, &vp.rect.x, &vp.rect.y);
   glfwGetWindowSize(vp.glfw_window, &vp.rect.w, &vp.rect.h);

   return !glfwWindowShouldClose(vp.glfw_window);
}

void set_viewport_name(string name) {
   vp.name = name;
#ifdef DEBUG
   string s = to_string(" (Compiled In Debug Mode)");
   char_list_append(&vp.name, &s);
#endif
   if (vp.glfw_window != NULL)
      glfwSetWindowTitle(vp.glfw_window, vp.name.data);
}

void set_viewport_size(vec2 v) {
   vp.rect.w = v[0];
   vp.rect.h = v[1];

   if (vp.glfw_window != NULL)
      glfwSetWindowSize(vp.glfw_window, vp.rect.w, vp.rect.h);
}

void set_viewport_position(vec2 v) {
   vp.rect.x = v[0];
   vp.rect.y = v[1];

   if (vp.glfw_window != NULL)
      glfwSetWindowPos(vp.glfw_window, vp.rect.w, vp.rect.h);
}

string get_viewport_name() { 
   return vp.name;
}

irect get_viewport_rect() {
   return vp.rect;
}
