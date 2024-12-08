#ifndef MYOS_INCLUDE_CONSOLE_H
#define MYOS_INCLUDE_CONSOLE_H

typedef enum {
  BLACK=0,
  BLUE=1,
  GREEN=2,
  CYAN=3,
  RED=4,
  MAGENTA=5,
  BROWN=6,
  LIGHT_GRAY=7,
  DARK_GRAY=8,
  LIGHT_BLUE=9,
  LIGHT_GREEN=10,
  LIGHT_CYAN=11,
  LIGHT_RED=12,
  LIGHT_MAGENTA=13,
  YELLOW=14,
  WHITE=15
} VGA_Color;

static const int VGA_WIDTH = 80;
static const int VGA_HEIGHT = 25;
static const int VGA_BYTES_PER_CHARACTER = 2;


void clear_terminal();
void print_character(char c);
void print_string(char* str);
void print_line(char* str);
void print_character_with_color(char c, VGA_Color bg_color, VGA_Color font_color);
void print_string_with_color(char* str, VGA_Color bg_color, VGA_Color font_color);
void print_line_with_color(char* str, VGA_Color bg_color, VGA_Color font_color);
void set_terminal_font_color(VGA_Color color);
void set_terminal_background_color(VGA_Color color);
void update_cursor();

#endif
