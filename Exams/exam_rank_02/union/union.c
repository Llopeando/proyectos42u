/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:28:16 by ullorent          #+#    #+#             */
/*   Updated: 2021/12/15 17:25:03 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	c;

	c = 0;
	while (str[c])
		c++;
	return (c);
}

int	ft_union_checker(char *str, char str2, int counter)
{
	int	c;

	c = 0;
	while (str[c] && c < counter)
	{
		if (str[c] == str2)
			return (1);
		c++;
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
			if (!ft_union_checker(argv[1], argv[1][c], c))
				write(1, &argv[1][c], 1);
			c++;
		}
		c = 0;
		while (argv[2][c])
		{
			if (!ft_union_checker(argv[1], argv[2][c], ft_strlen(argv[1]))
				&& !ft_union_checker(argv[2], argv[2][c], c))
				write (1, &argv[2][c], 1);
			c++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
