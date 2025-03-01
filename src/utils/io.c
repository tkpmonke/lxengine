#include "utils/io.h"

#include "unistd.h"

#ifdef LZCONSOLE_OUTPUT 
#ifdef LZUSE_ANSI_COLOR_CODES
void reset_terminal_colors() {
   write(STDOUT, "\033[0m", 4);
}
#endif

void print(string s) {
  write(STDOUT, s.data, s.size);  
}

void print_warning(string s) {
#ifdef LZUSE_ANSI_COLOR_CODES
   string warning = to_string("\033[1;93mWarning > ");
#else
   string warning = to_string("Warning > ");
#endif
   char_list_append(&warning, &s);
   write(STDOUT, warning.data, warning.size);  


#ifdef LZUSE_ANSI_COLOR_CODES
   reset_terminal_colors();
#endif
}

void print_error(string s) {
#ifdef LZUSE_ANSI_COLOR_CODES
   string warning = to_string("\033[1;91mError > ");
#else
   string warning = to_string("Error > ");
#endif
   char_list_append(&warning, &s);
   write(STDERR, warning.data, warning.size);  


#ifdef LZUSE_ANSI_COLOR_CODES
   reset_terminal_colors();
#endif
}

void print_fatal_error(string s) {
   print_error(s);

#ifdef LZUSE_ANSI_COLOR_CODES
   string error = to_string("\n\033[1;91mExiting...\n");
#else
   string error = to_string("\nExiting...\n");
#endif

   print(error);

#ifdef LZUSE_ANSI_COLOR_CODES
   reset_terminal_colors();
#endif
   exit(1);
}

// if the user doesn't want to have console output
#else

void print(string s) {}
void print_warning(string s) {}
void print_error(string s) {}
void print_fatal_error(string s) {}

#endif
