/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 10:17:35 by ullorent          #+#    #+#             */
/*   Updated: 2021/08/05 10:57:54 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	count;

	count = ft_strlen(str);
	while (str[count] != '\0')
	{
		if (str[count] == c)
		{
			return ((char *) str[count]);
		}
		count--;
	}
	if (str[count] == c)
	{
		return ((char *) str[count]);
	}
	return (NULL);
}
