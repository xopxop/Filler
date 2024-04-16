#include "stdio.h"
#include "unistd.h"

void throw_error(char *message) {
  dprintf(STDERR_FILENO, message);
  exit(2);
}

void get_dimension(int *height, int *width) {
}

int get_height(char **map) {
  return (0);
}

int get_width(char **map) {
  return (0);
}