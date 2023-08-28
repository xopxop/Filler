/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 00:05:45 by dthan             #+#    #+#             */
/*   Updated: 2023/08/28 10:50:17 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/get_next_line.h"

static int	contain_line_break(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
	{
		if (str[i] == '\0')
			return (0);
		i++;
	}
	return (1);
}

static int	get_line(char **line_ptr, char **storage_ptr)
{
	int		i;
	char	*temp_str;

	i = 0;
	while ((*storage_ptr)[i] != '\n' && (*storage_ptr)[i] != '\0')
		i++;
	if ((*storage_ptr)[i] == '\n')
	{
		(*storage_ptr)[i] = '\0';
		*line_ptr = ft_strdup(*storage_ptr);
		temp_str = *storage_ptr;
		*storage_ptr = ft_strdup(&(*storage_ptr)[i + 1]);
		free(temp_str);
	}
	else if ((*storage_ptr)[i] == '\0')
	{
		ft_printf("%d\n", i);
		*line_ptr = *storage_ptr;
		*storage_ptr = NULL;
	}
	return (1);
}

static int	error_handle(char **line_ptr, char **storage_ptr)
{
	if (*storage_ptr)
		free(*storage_ptr);
	if (*line_ptr)
		free(*line_ptr);
	*storage_ptr = NULL;
	*line_ptr = NULL;
	return (-1);
}

static int	read_input(int fd, char **storage, ssize_t *bytes)
{
	char	buffer[BUFF_SIZE + 1];

	*bytes = read(fd, buffer, BUFF_SIZE);
	if (*bytes <= 0)
		return (0);
	buffer[*bytes] = '\0';
	if (!(*storage))
		*storage = ft_strdup(buffer);
	else
		*storage = ft_strjoin_and_free_string1(*storage, buffer);
	if (contain_line_break(*storage))
		return (0);
	return (1);
}

int	get_next_line2(const int fd, char **line)
{
	static char	*storage[FD_MAX];
	ssize_t		bytes;

	if (fd < 0 || fd > FD_MAX)
		return (-1);
	if (storage[fd] && contain_line_break(storage[fd]))
		return (get_line(line, &storage[fd]));
	while (read_input(fd, &storage[fd], &bytes))
		;
	if (bytes == -1)
		return (error_handle(line, &storage[fd]));
	else if (bytes == 0 && storage[fd])
		return (get_line(line, &storage[fd]));
	else if (bytes == 0 && !storage[fd])
	{
		*line = NULL;
		return (0);
	}
	return (get_line(line, &storage[fd]));
}
