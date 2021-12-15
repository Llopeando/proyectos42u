/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 09:46:17 by ullorent          #+#    #+#             */
/*   Updated: 2021/09/15 16:21:54 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char		*mem;
	size_t		c;

	c = start;
	if (!s)
		return (NULL);
	if (ft_strlen(s + start) < len)
	{
		mem = (char *)malloc(ft_strlen(s + start) + 1);
		len = ft_strlen(s + start);
	}
	else if (start < ft_strlen(s))
		mem = malloc(len + 1);
	else
		mem = (char *)malloc(1);
	if (!mem || !s)
		return (NULL);
	while (len > 0 && start < ft_strlen(s))
	{
		mem[c - start] = s[c];
		c++;
		len--;
	}
	mem[c - start] = '\0';
	return (mem);
}
