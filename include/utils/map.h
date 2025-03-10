#pragma once

#define MAKE_MAP(key, value) \
typedef struct { \
} key##_##value##_map;

MAKE_MAP(int, char);
