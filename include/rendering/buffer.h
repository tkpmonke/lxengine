#pragma once

#include "utils/types.h"
#include "volk.h"

typedef union {
   struct {
      lxuint buffer_id;
      lxuint target;
   } opengl;

   struct {
      
   } vulkan;
} gpu_buffer;
