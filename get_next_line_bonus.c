/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:14:39 by bbrassar          #+#    #+#             */
/*   Updated: 2021/06/09 18:10:30 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line_bonus.h"

void	gnl_join(char **line, char *buffer, size_t n)
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
	}
}

int	gnl_copy_until_line_break(char **line, char *buffer, char **rest)
{
	int	i;

	if (!line)
		return (0);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		++i;
	gnl_join(line, buffer, i);
	free(*rest);
	if (buffer[i])
		*rest = ft_strdup(buffer + i + 1);
	else
		*rest = NULL;
	i = !!buffer[i];
	free(buffer);
	return (i);
}

int	get_next_line(int fd, char **line)
{
	static t_fd_list	*head = NULL;
	t_fd_list			*list;
	char				*buffer;
	int					bytes;

	list = gnl_find_or_create_fd(&head, fd);
	bytes = 1;
	*line = NULL;
	if (list && list->rest)
		if (gnl_copy_until_line_break(line, ft_strdup(list->rest), &list->rest))
			return (1);
	while (bytes > 0)
	{
		buffer = malloc(sizeof (char) * (BUFFER_SIZE + 1));
		bytes = read(fd, ft_memset(buffer, 0, BUFFER_SIZE + 1), BUFFER_SIZE);
		if (bytes == -1)
			free(buffer);
		else if (gnl_copy_until_line_break(line, buffer, &list->rest))
			return (1);
	}
	return (gnl_remove_fd(&head, fd, bytes));
}

/*
int	_get_next_line(int fd, char **line)
{
	static char	*rest = NULL;
	char		*buffer;
	int			bytes;

	bytes = 1;
	*line = NULL;
	if (rest)
		if (gnl_copy_until_line_break(line, ft_strdup(rest), &rest))
			return (1);
	while (bytes > 0)
	{
		buffer = malloc(sizeof (char) * (BUFFER_SIZE + 1));
		bytes = read(fd, ft_memset(buffer, 0, BUFFER_SIZE + 1), BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			return (-1);
		}
		else if (gnl_copy_until_line_break(line, buffer, &rest))
			return (1);
	}
	return (bytes);
}
*/
