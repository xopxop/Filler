/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:10:49 by dthan             #+#    #+#             */
/*   Updated: 2023/08/25 16:00:34 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int main(void)
{
	t_board *board = new_board();
	t_player *player = new_player();

	while ("playing")
	{
		t_ordinate play = player_play();
		if (play == NULL)
			break;
		delete_ordinate(play);
	}
	delete_board(board);
	delete_player(player);
	return (0);
}
