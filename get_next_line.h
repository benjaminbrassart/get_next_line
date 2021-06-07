/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 10:11:48 by bbrassar          #+#    #+#             */
/*   Updated: 2021/06/07 11:00:16 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16
# endif

# include <string.h>

int		gnl_strjoin(char **line, char *s, size_t n);

int		get_next_line(int fd, char **line);

void	*ft_memmove(void *dst, void const *src, size_t n);

void	*ft_memset(void *s, int c, size_t n);

char	*ft_strchr(char const *s, int c);

#endif
