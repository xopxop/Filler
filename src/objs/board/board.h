#ifndef BOARD_H
# define BOARD_H

typedef struct s_board
{
	int	height;
	int	width;
	char	**map;
}	t_board;

t_board	*new_board(void);
void	delete_board(t_board *obj);

#endif
