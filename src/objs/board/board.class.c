#include "stdlib.h"
#include "board.interface.h"

static void destructor(t_board *obj) {
	int	i = 0;

	while (obj->map[i]) {
		free(obj->map[i]);
		obj->map[i] = NULL;
		i++;
	}
	free(obj->map);
	obj->map = NULL;
}

static void constructor(t_board *obj) {
	get_dimension(&(obj->height), &(obj->width));
	obj->map = get_map();
	if (obj->height != get_height(obj->map)) {
		throw_error("Invalid height.");
	}
	if (obj->width != get_width(obj->map)) {
		throw_error("Invalid width.");
	}
}

void delete_board(t_board *obj) {
	destructor(obj);
	free(obj);
}

t_board *new_board(void) {
	t_board *obj;
	
	obj = (t_board*)malloc(sizeof(t_board));
	constructor(obj);
	return obj;
}
