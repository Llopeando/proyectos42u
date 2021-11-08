/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 11:20:52 by ullorent          #+#    #+#             */
/*   Updated: 2021/07/01 17:12:02 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i_counter;
	int	c_var;

	if (argc > 0)
	{
		i_counter = 0;
		while (argv[0][i_counter] != '\0')
		{
			c_var = argv[0][i_counter];
			write(1, &c_var, 1);
			i_counter++;
		}
		write(1, "\n", 1);
	}
	return (0);
}
