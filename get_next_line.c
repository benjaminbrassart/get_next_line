/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:14:39 by bbrassar          #+#    #+#             */
/*   Updated: 2021/06/08 16:39:44 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int	gnl_free(char **p_str, int rv)
{
	free(*p_str);
	*p_str = NULL;
	return (rv);
}

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

int	gnl_copy_until_line_break(char **line, char *buffer, char **rest)
{
	size_t	i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		++i;
	gnl_join(line, buffer, i);
	free(*rest);
	if (buffer[i])
	{
		*rest = ft_strdup(buffer + i + 1);
		return (1);
	}
	*rest = NULL;
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*rest = NULL;
	char		*buffer;
	int			bytes;

	*line = NULL;
	if (rest)
	{
		buffer = ft_strdup(rest);
		if (gnl_copy_until_line_break(line, buffer, &rest))
			return (gnl_free(&buffer, 1));
		free(buffer);
	}
	bytes = 1;
	while (bytes)
	{
		buffer = malloc(sizeof (char) * (BUFFER_SIZE + 1));
		bytes = read(fd, ft_memset(buffer, 0, BUFFER_SIZE + 1), BUFFER_SIZE);
		if (bytes == -1)
			return (gnl_free(&buffer, -1));
		if (gnl_copy_until_line_break(line, buffer, &rest))
			return (gnl_free(&buffer, 1));
		free(buffer);
	}
	return (gnl_free(&rest, 0));
}
