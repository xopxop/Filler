#include "filler.class.h"
#include "board.class.h"
#include "token.class.h"

int main(void) {
	t_filler *filler = new_filler();

	while (is_game_over()) {
		t_board *board = new_board();
		t_token *token = new_token();
		filler->play(*filler, *board, *token);
		delete_board(board);
		delete_token(token);
	}
	delete_filler(filler);
	return (0);
}
