/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:14:39 by bbrassar          #+#    #+#             */
/*   Updated: 2021/06/08 23:58:17 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int	gnl_join(char **line, char *buffer, size_t n)
{
	size_t	i;
	char	*s;

	i = 0;
	while (*line && (*line)[i])
		++i;
	s = malloc(i + n + 1);
	if (s)
	{
		ft_memmove(s, *line, i);
		ft_memmove(s + i, buffer, n);
		s[i + n] = 0;
		free(*line);
		*line = s;
		return (1);
	}
	return (0);
}

int	gnl_copy_until_line_break(char **line, char **buffer,
		char (*rest)[BUFFER_SIZE + 1])
{
	size_t	i;

	i = 0;
	while ((*buffer)[i] && (*buffer)[i] != '\n')
		++i;
	gnl_join(line, *buffer, i);
	ft_memset(&rest[0][0], 0, BUFFER_SIZE + 1);
	ft_memmove(&rest[0][0], *buffer + i + 1, BUFFER_SIZE - i);
	i = !!(*buffer)[i];
	free(*buffer);
	return (i);
}

int	get_next_line(int fd, char **line)
{
	static char	rest[BUFFER_SIZE + 1] = {0};
	char		*buffer;
	int			bytes;

	*line = NULL;
	if (rest[0])
	{
		buffer = ft_strdup(rest);
		if (gnl_copy_until_line_break(line, &buffer, &rest))
			return (1);
	}
	bytes = 1;
	while (bytes)
	{
		buffer = malloc(sizeof (char) * (BUFFER_SIZE + 1));
		bytes = read(fd, ft_memset(buffer, 0, BUFFER_SIZE + 1), BUFFER_SIZE);
		if (bytes == -1)
			return (-1);
		if (gnl_copy_until_line_break(line, &buffer, &rest))
			return (1);
	}
	free(*line);
	return (0);
}
