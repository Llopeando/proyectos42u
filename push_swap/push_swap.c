/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:23:02 by ullorent          #+#    #+#             */
/*   Updated: 2022/01/19 16:43:30 by ullorent         ###   ########.fr       */
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
	if (argc < 2)
	{
		write(1, "Erorr\n", 6);
		exit (1);
	}
	while (argv[c])
	{
		if ((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A'))
		{
			write(1, "Error\n", 6);
			write(1, "is not int\n", 11);
			exit (1);
		}
		c++;
	}
	write(1, "OK\n", 3);
	return (0);
}
