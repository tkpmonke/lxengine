#pragma once

#include "rendering/renderer.h"
#include "rendering/material.h"

void gl_initilize(void);

void gl_draw(draw_call_params*);

void gl_set_clear_color(vec4);
void gl_clear(void);

void gl_display_to_viewport(void);

gpu_buffer gl_create_buffer(size_t, const void*, int);
void gl_bind_buffer(gpu_buffer*);
void gl_update_buffer(gpu_buffer*, size_t, const void*);
void gl_destroy_buffer(gpu_buffer*);

shader gl_create_shader(string vert, string frag);
void gl_destroy_shader(shader*);

render_mesh gl_create_render_mesh(mesh*);
void gl_destroy_render_mesh(render_mesh*);

const extern renderer opengl_renderer;

struct gl_render_mesh_data {
   unsigned int vao, vbo, ebo, indexCount;
};
