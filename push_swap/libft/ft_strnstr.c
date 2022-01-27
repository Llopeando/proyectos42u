/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 10:51:07 by ullorent          #+#    #+#             */
/*   Updated: 2021/12/15 16:18:27 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	c;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i])
	{
		c = 0;
		while (haystack[i + c] == needle[c] && (i + c) < len)
		{
			if (needle[c + 1] == '\0')
				return ((char *)haystack + i);
			c++;
		}
		i++;
	}
	return (NULL);
}
