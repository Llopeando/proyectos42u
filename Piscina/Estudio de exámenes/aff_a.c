/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:42:04 by ullorent          #+#    #+#             */
/*   Updated: 2021/07/01 19:52:01 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int strc, char **strv)
{
	int	i;

	i = 0;
	if (strc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (strv[1][i])
	{
		while (strv[1][i] == 'a')
		{
			write(1, "a\n", 2);
			return (0);
		}
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
