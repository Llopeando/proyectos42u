/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:48:54 by ullorent          #+#    #+#             */
/*   Updated: 2021/10/19 18:46:29 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strn(const char *str)
{
	size_t	c;

	c = 0;
	if (!str)
		return (0);
	while (str[c] != '\n' && str[c] != '\0')
	{
		c++;
	}
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
		if (str[c] != '\n' && str[c] == '\0')
			return (0);
		c++;
	}
	return (1);
}

char	*ft_substr(char **s, unsigned int start, size_t len, int boo)
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
		free (*s);
	return (mem);
}

void	ft_freejoinmem(char **s1, char **s2)
{
	if (s1 && *s1)
		free (*s1);
	if (s2 && *s2)
		free (*s2);
	return ;
}

char	*ft_strjoin(char **s1, char **s2)
{
	int		c;
	int		i;
	char	*mem;

	c = 0;
	i = 0;
	if (!*s2)
		return (NULL);
	mem = malloc(ft_strlen(*s1) + ft_strlen(*s2) + 1);
	if (!mem)
		return (NULL);
	while (((size_t)c) < ft_strlen(*s1))
		*mem++ = (*s1)[c++];
	while ((*s2)[i] != '\0')
		*mem++ = (*s2)[i++];
	*mem = '\0';
	ft_freejoinmem(((char **)s1), ((char **)s2));
	return (mem - c - i);
}
