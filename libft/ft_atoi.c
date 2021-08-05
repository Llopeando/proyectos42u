/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 11:34:58 by ullorent          #+#    #+#             */
/*   Updated: 2021/08/05 12:00:59 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	c;
	int	pm;
	int	absol;
	int	current;

	c = 0;
	pm = -1;
	if (str[0] == '-')
	{
		pm = '-';
		c++;
	}
	if (str[0] == '+')
	{
		c++;
	}
	while (str[c] != '\0')
	{
		current = (int) str[c] - '0';
		if (current < 0 || current > 9)
			return (absol);
		absol = absol * 10 + current;
		c++;
	}
	return (pm * absol);
}
