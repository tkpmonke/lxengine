#include "rendering/opengl/opengl_renderer.h"

const renderer opengl_renderer = {
   .initilize = gl_initilize,

   .create_buffer = gl_create_buffer,
   .bind_buffer = gl_bind_buffer,
   .update_buffer = gl_update_buffer,
   .destroy_buffer = gl_destroy_buffer,

   .display_to_viewport = gl_display_to_viewport,

   .clear = gl_clear,
   .set_clear_color = gl_set_clear_color,
   
   .create_shader = gl_create_shader,
   .destroy_shader = gl_destroy_shader,

   .create_render_mesh = gl_create_render_mesh,
   .destroy_render_mesh = gl_destroy_render_mesh,

   .draw = gl_draw,
};
