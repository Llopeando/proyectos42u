/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 12:34:53 by ullorent          #+#    #+#             */
/*   Updated: 2021/08/02 13:15:07 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	c;
	size_t	d;

	c = 0;
	d = 0;
	while (dst[c] != '\0')
	{
		c++;
	}
	while (src[d] != '\0' && (n - 1))
	{
		dst[c] = src[d];
		c++;
		d++;
	}
	dst[c] = '\0';
	return (c + d);
}
