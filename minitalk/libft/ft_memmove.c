/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:29:17 by ullorent          #+#    #+#             */
/*   Updated: 2021/09/08 12:00:34 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	c;

	c = 0;
	if (!dst && !src)
		return (0);
	if ((size_t)dst - (size_t)src < len)
	{
		c = len - 1;
		while (c < len)
		{
			((char *)dst)[c] = ((char *)src)[c];
			c--;
		}
	}
	else
	{
		while (c < len)
		{
			((char *)dst)[c] = ((char *)src)[c];
			c++;
		}
	}
	return (dst);
}
