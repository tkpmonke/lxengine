#pragma once

#include "utils/types.h"

#define STDIN 0
#define STDOUT 1
#define STDERR 2

// undefine this if you don't want colored text with errors/warnings
#ifndef _WIN32
#define LZUSE_ANSI_COLOR_CODES
#endif

#define LZCONSOLE_OUTPUT

void print(string);
void print_warning(string);
void print_error(string);
void print_fatal_error(string);
