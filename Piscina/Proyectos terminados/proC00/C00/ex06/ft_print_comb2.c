/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 17:21:01 by ullorent          #+#    #+#             */
/*   Updated: 2021/06/17 12:16:33 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	numbers_2(char a, char b, char c, char d);
void	final_printer(char a, char b, char c, char d);

void 	ft_print_comb2(void)
{
	char	a;
	char	b;
	char	c;
	char	d;

	a = '0';
	b = '0';
	c = '0';
	while (c <= '9')
	{
		d = '0';
		while (d <= '9')
		{
			numbers_2(a, b, c, d);
			d++;
		}
		c++;
	}
}

void	numbers_2(char a, char b, char c, char d)
{
	a = '0';
	while (a <= '9')
	{
		b = '0';
		while (b <= '9')
		{
			final_printer(a, b, c, d);
			b++;
		}
		a++;
	}
}

void	final_printer(char a, char b, char c, char d)
{
	if (c < a || (c == a && d < b))
	{
		write(1, &c, 1);
		write(1, &d, 1);
		write(1, " ", 1);
		write(1, &a, 1);
		write(1, &b, 1);
		if (c != '9' || d != '8' || a != '9' || b != '9')
			write(1, ", ", 2);
	}
}
