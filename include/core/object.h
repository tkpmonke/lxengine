#pragma once

#include "utils/types.h"

typedef struct {
   string name;
   string tag;
   lxuint id;
} object;
MAKE_LIST(object);
