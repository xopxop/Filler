#ifndef HEAT_MAP_H
#define HEAT_MAP_H

typedef struct s_heat_map
{
	int	height;
	int	width;
	int	**map;
}	t_heat_map;

t_heat_map	*new_heat_map(char **map, int height, int width, char player_char);
void	delete_heat_map(t_heat_map *obj);

#endif