#include "heat_map.h"
#include "board.h"
#include "filler.h"
#include "stdlib.h"

static void destructor(t_heat_map *obj) {
  int i = 0;

  while (i < obj->height) {
    free(obj->map[i]);
    i++;
  }
  free(obj->map);
  obj->height = 0;
  obj->width = 0;
}

void delete_heat_map(t_heat_map *obj) {
  destructor(obj);
  free(obj);
}

static void constructor(t_heat_map *obj, char **map, int height, int width, char player_char) {
  obj->map = get_heat_map(map, height, width, player_char);
  obj->height = height;
  obj->width = width;
}

t_heat_map	*new_heat_map(char **map, int height, int width, char player_char) {
  t_heat_map *obj;
	
	obj = (t_heat_map*)malloc(sizeof(t_heat_map));
	constructor(obj, map, height, width, player_char);
	return obj;
}
