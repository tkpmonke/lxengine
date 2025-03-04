#pragma once

#include "utils/list.h"
#include "cglm/vec2.h"

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

