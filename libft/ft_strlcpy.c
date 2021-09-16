/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 11:53:35 by ullorent          #+#    #+#             */
/*   Updated: 2021/08/30 10:24:07 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	d;
	size_t	e;

	if (!src)
		return (0);
	d = 0;
	e = 0;
	while (src[d] != '\0')
		d++;
	if (n != 0)
	{
		while (src[e] != '\0' && (n - 1))
		{
			dst[e] = src[e];
			e++;
			n--;
		}
		dst[e] = '\0';
	}
	return (d);
}
