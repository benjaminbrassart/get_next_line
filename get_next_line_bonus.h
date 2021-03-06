/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 10:11:48 by bbrassar          #+#    #+#             */
/*   Updated: 2021/06/09 18:07:35 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16
# endif

# include <string.h>

typedef struct s_fd_list	t_fd_list;

struct s_fd_list
{
	int			fd;
	char		*rest;
	t_fd_list	*next;
};

int			get_next_line(int fd, char **line);

void		*ft_memmove(void *dst, void const *src, size_t n);

void		*ft_memset(void *s, int c, size_t n);

char		*ft_strchr(char const *s, int c);

char		*ft_strdup(char const *s);

t_fd_list	*gnl_find_or_create_fd(t_fd_list **head, int fd);

int			gnl_remove_fd(t_fd_list **head, int fd, int rv);

#endif
