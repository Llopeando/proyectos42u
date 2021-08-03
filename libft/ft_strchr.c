/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 12:12:09 by ullorent          #+#    #+#             */
/*   Updated: 2021/08/03 12:42:07 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == c)
		{
			return ((char *) str);
		}
		str++;
	}
	if (*str == c)
	{
		return ((char *) str);
	}
	return (NULL);
}
