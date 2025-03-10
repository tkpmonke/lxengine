#include "rendering/opengl/opengl_renderer.h"
#include "utils/io.h"
#include "GL/glew.h"

shader gl_create_shader(string vert, string frag) {
   unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
   glShaderSource(vertexShader, 1, (const char**)&vert.data, NULL);
   glCompileShader(vertexShader);

   int success;
   char infoLog[512];
   glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
   if (!success)
   {
      glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
      print_error(to_string("GL_COMPILE_STATUS > VERTEX"));
      print(to_string(infoLog));
   }

   unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
   glShaderSource(fragmentShader, 1, (const char**)&frag.data, NULL);
   glCompileShader(fragmentShader);

   glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
   if (!success)
   {
      glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
      print_error(to_string("GL_COMPILE_STATUS > FRAGMENT"));
      print(to_string(infoLog));
   }

   unsigned int shaderProgram = glCreateProgram();
   glAttachShader(shaderProgram, vertexShader);
   glAttachShader(shaderProgram, fragmentShader);
   glLinkProgram(shaderProgram);

   glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
   if (!success) {
      glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
      print_error(to_string("GL_LINK_STATUS"));
      print(to_string(infoLog));
   }
   glDeleteShader(vertexShader);
   glDeleteShader(fragmentShader);

   return (shader) {
      .shader_data = (int*)(unsigned long int)shaderProgram,
   };
}

void gl_destroy_shader(shader* s) {
   glDeleteProgram((unsigned long int)s->shader_data);
}
