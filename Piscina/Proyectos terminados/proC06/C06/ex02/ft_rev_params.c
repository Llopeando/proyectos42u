/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 13:17:41 by ullorent          #+#    #+#             */
/*   Updated: 2021/07/01 13:29:50 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	c;

	if (argc > 1)
	{
		i = argc - 1;
		while (i > 0)
		{
			c = 0;
			while (argv[i][c] != '\0')
			{
				write(1, &argv[i][c], 1);
				c++;
			}
			write(1, "\n", 1);
			i--;
		}
	}
	return (0);
}
