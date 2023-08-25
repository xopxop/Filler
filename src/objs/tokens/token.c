/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:56:34 by dthan             #+#    #+#             */
/*   Updated: 2023/08/25 15:13:57 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "token.h"
#include <string.h>

unsigned int get_width(char *str)
{
	char **data = strsplit(str, " ");
	char *full_width_str = data[2];
	char *width_str = strsplit(full_width_str)[1];
	return (atoi(width_str));
}

unsigned int get_height(char *str)
{
	char **data = strsplit(str, " ");
	char *height_str = str[1];
	return (atoi(height_str));
}

char **get_map(char **data, unsigned int height, unsigned int width)
{
	char **map = (char **)malloc(sizeof(char*) * (height + 1));
	char **token;

	for (unsigned int i = 0; i < height; i++)
	{
		token = strsplit(data[i], " ");
		map[i] = token[1];
	}
	map[height] = NULL;
	return map;
}

t_token *new_token(char **raw_data)
{
	t_token *obj;

	obj = (t_token *)malloc(sizeof(t_token));
	obj->height = get_height;
	obj->width = get_width;
	obj->data = get_map;
	return (obj);
}