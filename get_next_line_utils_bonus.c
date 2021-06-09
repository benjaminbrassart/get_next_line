/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 10:24:28 by bbrassar          #+#    #+#             */
/*   Updated: 2021/06/09 18:08:00 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line_bonus.h"

void	*ft_memmove(void *dst, void const *src, size_t n)
{
	unsigned char		*d;
	unsigned char const	*s;
	size_t				i;

	d = dst;
	s = src;
	i = 0;
	while (i < n)
	{
		if (d < s)
			d[n - i - 1] = s[n - i - 1];
		else
			d[i] = s[i];
		++i;
	}
	return (dst);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	ch;

	d = s;
	ch = c;
	while (n--)
		*d++ = ch;
	return (s);
}

char	*ft_strdup(char const *s)
{
	size_t	i;
	char	*str;

	i = 0;
	while (s[i])
		++i;
	str = malloc(sizeof (char) * (i + 1));
	if (str)
	{
		ft_memmove(str, s, i);
		str[i] = 0;
	}
	return (str);
}

t_fd_list	*gnl_find_or_create_fd(t_fd_list **head, int fd)
{
	t_fd_list	*list;

	list = *head;
	while (list)
	{
		if (fd == list->fd)
			return (list);
		list = list->next;
	}
	list = malloc(sizeof (*list));
	if (list)
	{
		list->fd = fd;
		list->rest = NULL;
		list->next = *head;
		*head = list;
	}
	return (list);
}

int	gnl_remove_fd(t_fd_list **head, int fd, int rv)
{
	t_fd_list	*prev;
	t_fd_list	*list;

	prev = NULL;
	list = *head;
	while (list)
	{
		if (list->fd == fd)
		{
			if (prev)
				prev->next = list->next;
			else
				*head = list->next;
			free(list->rest);
			free(list);
			break ;
		}
		prev = list;
		list = list->next;
	}
	return (rv);
}
