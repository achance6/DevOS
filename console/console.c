#include <stdint.h>
#include "console.h"
#include "portmap.h"

static char* const VGA_BUFFER = (char*) 0xb8000;
static int terminal_position = 0;
// Default font color will be light gray
static VGA_Color terminal_font_color = LIGHT_GRAY;
// Default background color is black
static VGA_Color terminal_background_color = BLACK;
static int spaces_in_tab = 8;
static const VGA_Color default_color = LIGHT_GRAY;

void clear_terminal() {
  for (int i = 0; i < VGA_WIDTH * VGA_HEIGHT - 1; i += VGA_BYTES_PER_CHARACTER) {
    VGA_BUFFER[i] = '\0';
    VGA_BUFFER[i + 1] = LIGHT_GRAY;
  }
  terminal_position = 0;

  update_cursor();
}

void print_character(char c) {
  print_character_with_color(c, terminal_background_color, terminal_font_color);
}

void print_string(char* str) {
  print_string_with_color(str, terminal_background_color, terminal_font_color);
}

void print_line(char* str) {
  print_line_with_color(str, terminal_background_color, terminal_font_color);
}

void print_character_with_color(char c, VGA_Color bg_color, VGA_Color font_color) {
  switch (c) {
  case '\n':
    terminal_position += VGA_WIDTH - (terminal_position % VGA_WIDTH);
    break;
    
  case '\t':
    terminal_position += spaces_in_tab - (terminal_position % spaces_in_tab);
    break;
    
  case '\b':
    terminal_position -= (terminal_position == 0) ? 0 : 1;
    VGA_BUFFER[terminal_position * VGA_BYTES_PER_CHARACTER] = '\0';
    VGA_BUFFER[(terminal_position * VGA_BYTES_PER_CHARACTER) + 1] = LIGHT_GRAY;
    break;

  case '\r':
    terminal_position -= terminal_position % VGA_WIDTH;
    break;
    
  default:
    VGA_BUFFER[terminal_position * VGA_BYTES_PER_CHARACTER] = c;
    VGA_BUFFER[(terminal_position * VGA_BYTES_PER_CHARACTER) + 1] = (bg_color << 4 | font_color);
    terminal_position++;
  }

  update_cursor();
}

void print_string_with_color(char* str, VGA_Color bg_color, VGA_Color font_color) {
  for (int i = 0; str[i] != '\0'; i++) {
    print_character_with_color(str[i], bg_color, font_color);
  }
}

void print_line_with_color(char* str, VGA_Color bg_color, VGA_Color font_color) {
  print_string_with_color(str, bg_color, font_color);
  print_character('\n');
}

void set_terminal_font_color(VGA_Color color) {
  terminal_font_color = color;
}

void set_terminal_background_color(VGA_Color color) {
  terminal_background_color = color;
}

void update_cursor() {
  uint16_t cursor_position = terminal_position;

  outb(0x3D4, 0x0F);

  outb(0x3D5, (uint8_t) (cursor_position));

  outb(0x3D4, 0x0E);
  
  outb(0x3D5, (uint8_t) (cursor_position >> 8));
}
