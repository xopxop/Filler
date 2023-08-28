/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 01:39:52 by dthan             #+#    #+#             */
/*   Updated: 2023/08/28 00:14:42 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 3
# define FD_MAX 256
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft.h"

int	get_next_line(int fd, char **line);
int	get_next_line2(int fd, char **line);

#endif
