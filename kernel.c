#include "console.h"

void main() {
  char* str = "Hello World";

  clear_terminal();
  print_string("HELLO");
  print_line("WORLD");
  print_string("TODAY");

  return;
}


