/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:11:01 by ullorent          #+#    #+#             */
/*   Updated: 2021/12/16 16:53:31 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

int	ft_strlen(char *str)
{
	int	c;

	c = 0;
	while (str[c])
		c++;
	return (c);
}

void	ft_putchar_c(char c, int *num)
{
	write(1, &c, 1);
	(*num)++;
}

void	ft_s_function(char *str, int *num)
{
	if (!str)
		*num += write(1, "(null)", 6);
	else
		*num += write(1, str, ft_strlen(str));
}

void	ft_d_function(int n, int *num)
{
	if (n == -2147483647)
	{
		ft_putchar_c('-', num);
		ft_putchar_c('2', num);
		n = 147483647;
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
		ft_d_function(n / 10, num);
	ft_d_function(n % 10, num);
}

void	ft_x_function(unsigned long int n, int *num)
{
	char	*base;

	base = "0123456789abcdef";
	if (n / 16 > 0)
	{
		ft_x_function(n / 16, num);
		ft_putchar_c(base[n % 16], num);
	}
	else
		ft_putchar_c(base[n], num);
}

void	ft_va(char let, va_list args, int *num)
{
	if (let == 's')
		ft_s_function(va_arg(args, char *), num);
	if (let == 'd')
		ft_d_function(va_arg(args, int), num);
	if (let == 'x')
		ft_x_function(va_arg(args, unsigned int), num);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		c;
	int		num;

	c = 0;
	num = 0;
	va_start(args, str);
	while (str[c] != '\0')
	{
		if (str[c] == '%')
		{
			ft_va(str[c + 1], args, &num);
			c += 2;
			continue ;
		}
		ft_putchar_c(str[c], &num);
		c++;
	}
	return (num);
}

int	main(void)
{
	char	*str;
	int		c;

	str = "Hola buenardos";
	c = -2147483647;
	ft_printf("Sies: %s\n", str);
	ft_printf("Sies2: %d\n", c);
	ft_printf("x (mio) -> %x\n", c);
	printf("x -> %x\n", c);
	return (0);
}
