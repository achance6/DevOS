#include "console.h"

static char* const VGA_BUFFER = (char*) 0xb8000;
static int terminal_position = 0;

void clear_terminal() {
  for (int i = 0; i < VGA_WIDTH * VGA_HEIGHT - 1; i += VGA_BYTES_PER_CHARACTER) {
    VGA_BUFFER[i] = '\0';
    VGA_BUFFER[i + 1] = 0x07;
  }
  terminal_position = 0;
}

void print_character(char c) {
  if (c == '\n') {
    terminal_position =
      terminal_position - (terminal_position % VGA_WIDTH) + VGA_WIDTH;
  } else {
    VGA_BUFFER[terminal_position * VGA_BYTES_PER_CHARACTER] = c;
    VGA_BUFFER[(terminal_position * VGA_BYTES_PER_CHARACTER) + 1] = 0x07;
    terminal_position++;
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
