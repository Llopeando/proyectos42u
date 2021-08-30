/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 13:05:12 by ullorent          #+#    #+#             */
/*   Updated: 2021/08/30 13:31:22 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n > 0)
	{
		if (*((unsigned char *)s1) != *((unsigned char *)s2))
		{
			return ((*((unsigned char *)s1) - *((unsigned char *)s2)));
		}
		n--;
		s1++;
		s2++;
	}
	return (0);
}
