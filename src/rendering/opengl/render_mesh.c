#include "rendering/opengl/opengl_renderer.h"
#include "utils/memory.h"

#include "GL/glew.h"

render_mesh gl_create_render_mesh(mesh* mesh) {
   unsigned int VAO;
   glGenVertexArrays(1, &VAO);
   glBindVertexArray(VAO);

   gpu_buffer vbo = gl_create_buffer(sizeof(vertex)*mesh->vertex_size, mesh->vertices, buffer_usage_data);

   gpu_buffer ebo = gl_create_buffer(sizeof(unsigned int)*mesh->index_size, mesh->indices, buffer_usage_elements);
   
   gl_bind_buffer(&vbo);

   glEnableVertexAttribArray(0);
   glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)(offsetof(vertex, position)));
   glEnableVertexAttribArray(1);
   glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)(offsetof(vertex, normal)));
   glEnableVertexAttribArray(2);
   glVertexAttribPointer(2, 2, GL_UNSIGNED_BYTE, GL_FALSE, sizeof(vertex), (void*)(offsetof(vertex, uv)));


   struct gl_render_mesh_data* o = LXMALLOC(sizeof(struct gl_render_mesh_data));

   o->vao = VAO;
   o->vbo = (long int)vbo.buffer_descriptor;
   o->ebo = (long int)ebo.buffer_descriptor;
   o->indexCount = mesh->index_size;

   return (render_mesh) { o };
}

void gl_destroy_render_mesh(render_mesh* rm) {
   struct gl_render_mesh_data* rmd = rm->data;
   glDeleteVertexArrays(1, &rmd->vao);
   glDeleteBuffers(1, &rmd->vbo);
   glDeleteBuffers(1, &rmd->ebo);
   LXFREE(rmd);
}
