/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 12:37:34 by ullorent          #+#    #+#             */
/*   Updated: 2021/09/14 12:47:00 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*mem;
	int		c;

	c = 0;
	if (!s)
		return (NULL);
	mem = ft_strdup(s);
	if (!mem)
		return (NULL);
	while (mem[c] != '\0')
	{
		mem[c] = f(c, mem[c]);
		c++;
	}
	return (mem);
}
