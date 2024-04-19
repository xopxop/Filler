#include "unistd.h"
#include "token.interface.h"

static void destructor(t_token *obj) {
	int i = 0;
	
	while (obj->map[i]) {
		free(obj->map[i]);
		obj->map = NULL;
		i++;
	}
	free(obj->map);
	obj->map = NULL;
}

static void constructor(t_token *obj) {
	get_dimension(&(obj->height), &(obj->width));
	obj->map = get_map();
	if (obj->height != get_height(obj->map)) {
		throw_error("Invalid height.");
	}
	if (obj->width != get_width(obj->map)) {
		throw_error("Invalid width.");
	}
}

void delete_token(t_token *obj)
{
	destructor(obj);
	free(obj);
}

t_token *new_token(char **raw_data)
{
	t_token *obj;

	obj = (t_token *)malloc(sizeof(t_token));
	constructor(obj);
	return (obj);
}
