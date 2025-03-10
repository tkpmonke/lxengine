#pragma once

#include "utils/types.h"
#include "GLFW/glfw3.h"

typedef struct {
   irect rect;
   string name;
   GLFWwindow* glfw_window;
} viewport;

void create_viewport();
void destroy_viewport();

void set_viewport_name(string);
void set_viewport_position(vec2);
void set_viewport_size(vec2);

string get_viewport_name();
irect get_viewport_rect();

int is_viewport_open();

viewport* get_viewport();
