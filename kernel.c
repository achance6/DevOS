#include "console.h"

void main() {
  clear_terminal();
  print_string("HELLO");
  print_line("WORLD");
  print_string("TODAY");
  print_character('c');
  print_character('\n');
  print_string_with_color("hello", YELLOW, CYAN);
  print_line_with_color("World", MAGENTA, GREEN);
  print_string("Today");
  
  return;
}


