void pre_populate(int **heat_map, char **map, int height, int width, char player_char) {
  int y = 0;
  int x;

  while (y < height) {
    x = 0;
    while (x < width) {
      if (map[y][x] == '.') {
        heat_map[y][x] = -1;
      } else if (map[y][x] == player_char) {
        heat_map[y][x] = -2;
      } else {
        heat_map[y][x] = 0;
      }
      x++;
    }
    y++;
  }
}

void calculate_distance(int **heat_map, int height, int width) {
  // need to develop
}

int **get_heat_map(char **map, int height, int width, char player_char) {
  int i = 0;
  int **heat_map = (int**)malloc(sizeof(int*) * height);

  while (i < height) {
    heat_map[i] = (int*)malloc(sizeof(int) * width);
    i++;
  }
  pre_populate(heat_map, map, height, width, player_char);
  calculate_distance(heat_map, height, width);
  return heat_map;
}
