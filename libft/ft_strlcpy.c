/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 12:17:22 by ullorent          #+#    #+#             */
/*   Updated: 2021/07/22 13:54:10 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	unsigned int	r;

	i = 0;
	r = 0;
	while (src[n] != '\0')
		n++;
	if (dest != '\0' && i < (src[n] - 1))
	{
		dest[n] = src[n];
		r++;
	}
	dest[n] = '\0';
}
