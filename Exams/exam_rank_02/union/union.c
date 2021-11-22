/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:56:49 by ullorent          #+#    #+#             */
/*   Updated: 2021/11/22 11:13:54 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	c;

	c = 0;
	while (str[c])
		c++;
	return (c);
}

int	ft_check_repeat(char *str, char str2, int c)
{
	int	counter;

	counter = 0;
	while (str[counter] && counter < c)
	{
		if (str[counter] == str2)
			return (1);
		counter++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	c;

	c = 0;
	if (argc == 3)
	{
		while (argv[1][c])
		{
			if (!ft_check_repeat(argv[1], argv[1][c], c))
				write(1, &argv[1][c], 1);
			c++;
		}
		c = 0;
		while (argv[2][c])
		{
			if (!ft_check_repeat(argv[1], argv[2][c], ft_strlen(argv[1]))
			&& !ft_check_repeat(argv[2], argv[2][c], c))
				write(1, &argv[2][c], 1);
			c++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
