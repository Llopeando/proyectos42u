/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 12:43:35 by ullorent          #+#    #+#             */
/*   Updated: 2021/08/05 13:01:36 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			co;
	unsigned char	*new;

	new = (unsigned char *)s;
	co = 0;
	while (co < n)
	{
		new[co] = 0;
		co++;
	}
	s = new;
}
