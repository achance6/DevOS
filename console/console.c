#include "console.h"

static int terminal_position = 0;

void clear_terminal() {
  for (int i = 0; i < VGA_WIDTH * VGA_HEIGHT; i++) {
    if (i % VGA_BYTES_PER_CHARACTER == 0) {
      VGA_BUFFER[i] = '\0';
    }
    else {
      VGA_BUFFER[i] = 0x07;
    }
  }
}

void print_character(char c) {
  if (VGA_BYTES_PER_CHARACTER == 2) {
    VGA_BUFFER[terminal_position * 2] = c;
    VGA_BUFFER[(terminal_position * 2) + 1] = 0x07;
    terminal_position += 1;
  }
  else {
    // abort();
  }
}

void print_string(char* str) {
  for (int i = 0; str[i] != '\0'; i++) {
    print_character(str[i]);
  }
}

void print_line(char* str) {
  print_string(str);
  print_character('\n');
}
