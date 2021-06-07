/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 10:12:29 by bbrassar          #+#    #+#             */
/*   Updated: 2021/06/07 10:55:08 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

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
		free(*line);
		*line = new;
		return (1);
	}
	return (0);
}

/*
int	get_next_line(int fd, char **line)
{
	static char	buffer[BUFFER_SIZE + 1];
	int			bytes;

	if (!(line && BUFFER_SIZE > 0))
		return (-1);
	free(*line);
	bytes = 1;
	while (bytes)
	{
		ft_memset(buffer, 0, BUFFER_SIZE + 1);
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (-1);
	}
	return (0);
}
*/
