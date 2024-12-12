#include <stdint.h>
#include "console.h"
#include "keyboard.h"

void main() {
  clear_terminal();
  uint8_t byte;

  /* print_line("Hello world"); */
  /* print_string("Hello world from the next line!"); */
  /* print_character('\r'); */

  while(1) {
    while ( byte = scan()) {
      print_character(charmap[byte]);
    }
  }
  
  return;
}


