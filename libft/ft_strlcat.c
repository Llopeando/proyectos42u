/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 10:41:01 by ullorent          #+#    #+#             */
/*   Updated: 2021/09/10 10:48:42 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int					final;
	unsigned int		d;
	unsigned int		d_counter;
	unsigned int		s_counter;

	d_counter = ft_strlen(dst);
	s_counter = ft_strlen(src);
	final = d_counter + s_counter;
	if (dstsize > d_counter && dstsize > 0)
	{
		d = 0;
		dstsize = dstsize - d_counter - 1;
		while (src[d] && dstsize > 0)
		{
			dst[d_counter] = src[d];
			d++;
			d_counter++;
			dstsize--;
		}
		dst[d_counter] = '\0';
		return (final);
	}
	else
		return (dstsize + s_counter);
}
