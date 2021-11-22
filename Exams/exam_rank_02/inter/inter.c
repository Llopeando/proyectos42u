/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:16:19 by ullorent          #+#    #+#             */
/*   Updated: 2021/11/18 17:10:05 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

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
			if (ft_check_repeat(argv[2], argv[1][c], ft_strlen(argv[2]))
				&& !ft_check_repeat(argv[1], argv[1][c], c))
				write(1, &argv[1][c], 1);
			c++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
