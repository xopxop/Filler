/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:10:49 by dthan             #+#    #+#             */
/*   Updated: 2023/08/26 00:04:19 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// typedef struct s_turn_info
// {
// 	t_board *board;
// 	t_token *token;
// } t_turn_info;

#include "../libft/includes/libft.h"
#include <fcntl.h>
#include "objs/player/player.h"
#include "objs/board/board.h"

void init_game_info(int fd, t_board *board, t_player *player)
{
	char *lines;
	char **tokens;
	
	(void)board;
	(void)player;
	while (get_next_line(STDIN_FILENO, &lines))
	{
		ft_dprintf(fd, "%s\n", lines);
		ft_dprintf(fd, "here\n");
	}
	ft_dprintf(fd, "End\n");
	free(lines);
}

int main(void)
{
	// t_ordinate *play;
	// t_turn_info *turn_info;
	// t_player *player;

	t_board *board = NULL;
	t_player *player = NULL;
	// char *lines;
	int file = open("log.txt", O_WRONLY | O_CREAT);

	init_game_info(file, board, player);
	// player = new_player();
	// get_next_line(STDIN_FILENO, &lines);
	// ft_strsplit(lines, '\n');
	// player = new_player(lines);
	while ("playing")
	{
		// get_next_line(STDIN_FILENO, &lines);
		// ft_dprintf(file, "%s\n", lines);
		//ft_printf("Here: ---- %s", lines);
		// turn_info->board = new_board();
		// turn_info->token = new_token();
		// play = player_play(board, piece, );
		// delete_board(board);
		// if (play == NULL)
		// 	break;
		// delete_ordinate(play);
	}
	// delete_player(player);
	return (0);
}
