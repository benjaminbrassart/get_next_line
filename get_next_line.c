/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 10:12:29 by bbrassar          #+#    #+#             */
/*   Updated: 2021/06/07 18:56:20 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int	gnl_free(char **buffer, int rv)
{
	free(*buffer);
	*buffer = NULL;
	return (rv);
}

int	gnl_strjoin(char **line, char *s, size_t n)
{
	char	*new;
	size_t	i;

	i = 0;
	while (*line && (*line)[i])
		++i;
	new = malloc(i + n + 1);
	if (new)
	{
		ft_memmove(new, *line, i);
		ft_memmove(new + i, s, n);
		new[i + n] = 0;
		*line = new;
		return (1);
	}
	return (0);
}

int	gnl_copy_until_line_break(char **line, char *buffer, char **rest)
{
	char	*diff;
	size_t	i;

	if (buffer != *rest)
		gnl_free(rest, 0);
	i = 0;
	diff = ft_strchr(buffer, '\n');
	if (diff)
		i = diff - buffer;
	else
		while (buffer[i])
			++i;
	gnl_strjoin(line, buffer, i);
	if (diff)
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
	int			r_bytes;

	if (rest)
		if (gnl_copy_until_line_break(line, rest, &rest))
			return (1);
	r_bytes = 1;
	while (r_bytes)
	{
		buffer = malloc(sizeof (char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (-1);
		ft_memset(buffer, 0, BUFFER_SIZE + 1);
		r_bytes = read(fd, buffer, BUFFER_SIZE);
		if (r_bytes == -1)
			return (gnl_free(&buffer, -1));
		if (gnl_copy_until_line_break(line, buffer, &rest))
			return (1);
		gnl_free(&buffer, 0);
	}
	return (0);
}
