/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 13:42:49 by ullorent          #+#    #+#             */
/*   Updated: 2021/06/17 14:05:54 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	numbers_function(char a, char b, int n);

void	ft_print_combn(int n)
{
	char	a;
	char	b;

	if (n == 2)
	{
		a = '0';
		while (a <= '9')
		{
			b = a + 1;
			while (b <= '9')
			{
				write(1, &a, 1);
				write(1, &b, 1);
				if (a != '8' || b != '9')
					write(1, ", ", 2);
				b++;
			}
			a++;
		}
	}
}
