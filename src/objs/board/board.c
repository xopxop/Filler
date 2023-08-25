/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 01:06:22 by dthan             #+#    #+#             */
/*   Updated: 2023/08/25 12:08:02 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "board.h"
#include <stdlib.h>
#include <string.h>

t_board	*new_board(char **data)
{
	unsigned int	index;
	t_board			*obj;

	index = 0;
	obj = (t_board *)malloc(sizeof(t_board));
	obj->height = get_height;
	obj->width = get_width;
	obj->map = get_map;
	return (obj);
}

void	*delete_board(t_board *obj)
{
	unsigned int	index;

	index = 0;
	while (index < obj->height)
	{
		free(obj->map[index]);
		index++;
	}
	free(obj->map);
	free(obj);
}
