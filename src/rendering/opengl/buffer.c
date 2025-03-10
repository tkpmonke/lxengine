#include "rendering/opengl/opengl_renderer.h"
#include "GL/glew.h"

void gl_bind_buffer(gpu_buffer* buffer) {
   glBindBuffer(buffer->usage == 0 ? GL_ARRAY_BUFFER : GL_ELEMENT_ARRAY_BUFFER, (unsigned long int)((*buffer).buffer_descriptor));
}

gpu_buffer gl_create_buffer(size_t size, const void* data, int usage) {
   gpu_buffer buffer = {
      NULL,
      0,
      usage
   };

   unsigned int i = 0;
   glGenBuffers(1, &i);
   buffer.buffer_descriptor = (long int*)(long int)i;
   gl_update_buffer(&buffer, size, data);

   return buffer;
}

void gl_update_buffer(gpu_buffer* buffer, size_t size, const void* data) {
   gl_bind_buffer(buffer);
   glBufferData(buffer->usage == 0 ? GL_ARRAY_BUFFER : GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

void gl_destroy_buffer(gpu_buffer* buffer) {
   lxuint b = (unsigned long int)buffer->buffer_descriptor;
   glDeleteBuffers(1, &b);
   buffer->buffer_descriptor = NULL;
}
