#pragma once

#include "utils/list.h"
#include "cglm/cglm.h"

MAKE_LIST(int);
MAKE_LIST(float);
MAKE_LIST(char);
MAKE_LIST(double);

typedef unsigned int lxuint;
typedef unsigned char lxuchar;

MAKE_LIST(lxuint);
MAKE_LIST(lxuchar);

typedef char_list string;
string to_string(char*);

typedef struct {
   int x, y;
   int w, h;
} irect;
