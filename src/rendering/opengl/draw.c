#include "rendering/opengl/opengl_renderer.h"
#include "GL/glew.h"

void gl_draw(draw_call_params* dcp) {
   glUseProgram((unsigned long int)get_shader(dcp->material->shader)->shader_data);
   glBindVertexArray(((struct gl_render_mesh_data*)dcp->render_mesh->data)->vao);
   glDrawElements(GL_TRIANGLES, ((struct gl_render_mesh_data*)dcp->render_mesh->data)->indexCount, GL_UNSIGNED_INT, 0);
}
