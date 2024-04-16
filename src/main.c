#include "filler.h"
#include "board.h"
#include "token.h"

void print_board(int fd, t_board *board)
{
	ft_dprintf(fd, "Dimension - [%d] [%d]\n", board->height, board->width);
	for (int i = 0; i < board->height; i++)
		ft_dprintf(fd, "[%s]\n", board->map[i]);
}

int main(void)
{
	// int file = open("log.txt", O_WRONLY | O_CREAT);
	t_filler *filler = new_filler();

	while (is_game_over())
	{
		t_board *board = new_board();
		t_token *token = new_token();
		filler->play(*filler, *board, *token);
		delete_board(board);
		delete_token(token);
	}
	delete_filler(filler);
	return (0);
}
