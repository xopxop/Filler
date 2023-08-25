/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 11:28:04 by dthan             #+#    #+#             */
/*   Updated: 2023/08/25 11:28:30 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static unsigned int get_height(char *str)
{
	return (atoi(str));
}

static unsigned int get_width(char *str)
{
	char number[128];

	strncpy(number, str, strlen(str) - 1);
	return (atoi(number));
}
