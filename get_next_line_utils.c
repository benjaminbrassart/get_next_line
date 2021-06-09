/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 10:24:28 by bbrassar          #+#    #+#             */
/*   Updated: 2021/06/09 17:48:16 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

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
	while (d && n--)
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
