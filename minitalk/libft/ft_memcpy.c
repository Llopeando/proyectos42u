/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 10:26:58 by ullorent          #+#    #+#             */
/*   Updated: 2021/08/30 10:55:32 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int		c;

	if (!dst && !src)
		return (NULL);
	c = 0;
	while (c < n)
	{
		((char *)dst)[c] = ((char *)src)[c];
		c++;
	}
	return (dst);
}
