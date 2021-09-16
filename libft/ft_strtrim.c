/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 12:35:54 by ullorent          #+#    #+#             */
/*   Updated: 2021/09/15 13:11:14 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		c;
	char	*str;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	c = ft_strlen(s1);
	while (s1[start] != '\0')
	{
		if (ft_strchr(set, s1[start]))
			start++;
		else
			break ;
	}
	while (c > start)
	{
		if (ft_strchr(set, s1[c - 1]))
			c--;
		else
			break ;
	}
	str = ft_substr(s1, start, (c - start));
	return (str);
}
