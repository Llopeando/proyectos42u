/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_diu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 11:05:56 by ullorent          #+#    #+#             */
/*   Updated: 2021/11/30 13:58:33 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_di(int n, int *num)
{
	if (n == -2147483648)
	{
		ft_putchar_c('-', num);
		ft_putchar_c('2', num);
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar_c('-', num);
		n = n * -1;
	}
	if (n < 10)
	{
		ft_putchar_c(n + 48, num);
		return ;
	}
	else
		ft_putnbr_di(n / 10, num);
	ft_putnbr_di(n % 10, num);
}

void	ft_putnbr_u(unsigned int n, int *num)
{
	if (n < 0)
	{
		ft_putchar_c('-', num);
		n = n * -1;
	}
	if (n < 10)
	{
		ft_putchar_c(n + 48, num);
		return ;
	}
	else
		ft_putnbr_u(n / 10, num);
	ft_putnbr_u(n % 10, num);
}
