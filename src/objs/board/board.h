/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 00:57:09 by dthan             #+#    #+#             */
/*   Updated: 2023/08/23 17:46:21 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOARD_H
# define BOARD_H

typedef struct s_board
{
	unsigned int	height;
	unsigned int	width;
	int				**map;
}	t_board;

t_board	*new_board(unsigned int row_count, unsigned int column_count);
void	delete_board(t_board *obj);

#endif
