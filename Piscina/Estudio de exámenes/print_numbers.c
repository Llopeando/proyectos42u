/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 18:57:13 by ullorent          #+#    #+#             */
/*   Updated: 2021/06/30 18:59:57 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_numbers(void)
{
	char	c;

	c = '0';
	while (c <= '9' && c >= '0')
	{
		write(1, &c, 1);
		c++;
	}
}

int	main(void)
{
	print_numbers();
}
