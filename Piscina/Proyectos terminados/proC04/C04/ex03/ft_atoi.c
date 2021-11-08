/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 11:39:49 by ullorent          #+#    #+#             */
/*   Updated: 2021/06/28 12:52:02 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	number;
	int	c;
	int	number2;

	c = 0;
	number = 0;
	number2 = 1;
	while (str[c] == ' ' || (str[c] >= '\t' && str[c] <= '\r'))
	{
		c++;
	}
	while (str[c] == '+' || str[c] == '-')
	{
		if (str[c] == '-')
			number2 *= -1;
		c++;
	}
	while (str[c] <= '9' && str[c] >= '0')
	{
		number = number * 10 + str[c] - '0';
		c++;
	}
	return (number * number2);
}
