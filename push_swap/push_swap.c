/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:23:02 by ullorent          #+#    #+#             */
/*   Updated: 2022/01/19 16:26:52 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	c;

	c = 0;
	if (argc < 1)
	{
		write(1, "Erorr\n", 6);
		return (0);
	}
	while (argv[c])
	{
		if (!ft_isdigit((int)argv[c]))
		{
			write(1, "Error\n", 6);
			write(1, "is not int\n", 11);
			return (0);
		}
		c++;
	}
	write(1, "OK\n", 3);
	return (0);
}
