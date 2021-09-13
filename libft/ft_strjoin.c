/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 11:50:46 by ullorent          #+#    #+#             */
/*   Updated: 2021/09/13 12:08:21 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	c;
	size_t	i;
	char	*mem;

	c = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	mem = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!mem)
		return (NULL);
	while (s1[c] != '\0')
	{
		*mem = s1[c];
		c++;
		mem++;
	}
	while (s2[i] != '\0')
	{
		*mem = s2[i];
		i++;
		mem++;
	}
	*mem = '\0';
	return (mem - c - i);
}
