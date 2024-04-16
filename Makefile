filler:
	# gcc -g -Wall -Wextra -Werror ./src/main.c ./src/objs/board/board.c -L ./libft -lft
	gcc ./src/main.c ./src/objs/board/board.c ./src/objs/player/player.c -L ./libft -lft