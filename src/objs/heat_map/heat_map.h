#ifndef BOARD_H
# define BOARD_H

typedef struct s_heat_map
{
	int	height;
	int	width;
	int	**map;
}	t_heat_map;

t_heat_map	*new_heat_map(t_board *board);
void	delete_heat_map(t_heat_map *obj);

#endif