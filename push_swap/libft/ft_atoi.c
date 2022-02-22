/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 11:34:58 by ullorent          #+#    #+#             */
/*   Updated: 2022/02/22 19:48:13 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned int		c;
	int					j;
	unsigned long int	lint;

	c = 0;
	j = 1;
	lint = 0;
	while ((str[c] == ' ') || (str[c] >= 9 && str[c] <= 13))
		c++;
	if (str[c] == '+' || str[c] == '-')
	{
		if (str[c] == '-')
			j = -1;
		c++;
	}
	while (str[c] <= '9' && str[c] >= '0')
	{
		lint = (lint * 10) + (str[c] - '0');
		c++;
	}
	if (lint > 9223372036854775807 && j == -1)
		return (0);
	if (lint > 9223372036854775807 && j == 1)
		return (-1);
	return (lint * j);
}
