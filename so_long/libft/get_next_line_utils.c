/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:48:54 by ullorent          #+#    #+#             */
/*   Updated: 2021/10/27 12:40:24 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strn(const char *str)
{
	size_t	c;

	c = 0;
	if (!str)
		return (0);
	while (str[c] != '\n' && str[c] != '\0')
		c++;
	return (c);
}

int	ft_strnboo(const char *str)
{
	size_t	c;

	c = 0;
	if (!str)
		return (1);
	while (str[c] != '\0')
	{
		if (str[c] == '\n')
			return (0);
		c++;
	}
	return (1);
}

char	*ft_substr_gnl(char **s, unsigned int start, size_t len, int boo)
{
	char		*mem;
	size_t		c;

	c = start;
	if (!*s)
		return (NULL);
	if (start < ft_strlen(*s))
		mem = malloc(len + 1);
	else
		mem = (char *)malloc(1);
	while (len > 0 && start < ft_strlen(*s))
	{
		mem[c - start] = (*s)[c];
		c++;
		len--;
	}
	mem[c - start] = '\0';
	if (boo)
		ft_linefreemem(s);
	return (mem);
}

char	*ft_strjoin_gnl(char **s1, char **s2)
{
	int			c;
	int			i;
	char		*mem;
	size_t		s1c;

	c = 0;
	i = 0;
	if (!*s2)
		return (NULL);
	s1c = ft_strlen(*s1);
	mem = malloc(s1c + ft_strlen(*s2) + 1);
	if (!mem)
		return (NULL);
	while (((size_t)c) < s1c)
		*mem++ = (*s1)[c++];
	while ((*s2)[i] != '\0')
		*mem++ = (*s2)[i++];
	*mem = '\0';
	ft_linefreemem(s1);
	ft_linefreemem(s2);
	return (mem - c - i);
}
