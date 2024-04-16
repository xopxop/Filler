#ifndef SHARED_LIB_H
#define SHARED_LIB_H

void throw_error(char *message);
char **get_map();
void get_dimension(int *height, int *width);
int get_height(char **map);
int get_width(char **map);

#endif
