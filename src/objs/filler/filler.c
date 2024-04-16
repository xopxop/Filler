#include "filler.h"
#include "board.h"
#include "token.h"
#include "stdlib.h"
#include "unistd.h"

int play(t_filler obj, t_board board, t_token token) {
  return (0);
}

void destructor_filler_obj(t_filler *obj) {
	obj->character = '\0';
	free(obj);
}

void constructor_filler_obj(t_filler *obj) {
	char *input;

	get_next_line(STDIN_FILENO, &input);
	if (!input)
		throw_error("Input line is not defined.");
	if (input[10] == '1')
		obj->character = 'x';
	else if (input[10] == '2')
		obj->character = 'o';
	else
		throw_error("Can't find player character.");
  obj->play = play;
}

void delete_filler(t_filler *obj) {
	destructor_player_obj(obj);
}

t_filler *new_filler(void)
{
	t_filler *obj;

	obj = (t_filler*)malloc(sizeof(t_filler));
	constructor_player_obj(obj);
	return (obj);
}
