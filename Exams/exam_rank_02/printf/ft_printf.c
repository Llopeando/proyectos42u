/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:11:31 by ullorent          #+#    #+#             */
/*   Updated: 2021/11/22 15:14:46 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

void	ft_putchar_c(char c, int *num)
{
	write(1, &c, 1);
	(*num)++;
}

int	ft_strlen(char *str)
{
	int	c;

	c = 0;
	while (str[c])
		c++;
	return (c);
}

void	ft_putstr_s(char *str, int *num)
{
	if (!num)
		*num += write(1, "(null)", 6);
	else
		*num += write(1, str, ft_strlen(str));
}

void	ft_putnbr_d(long int n, int *num)
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
		ft_putnbr_d(n / 10, num);
	ft_putnbr_d(n % 10, num);
}

void	ft_hexa_x(unsigned long int nbr, int *num)
{
	char	*base;

	base = "0123456789abcdef";
	if (nbr / 16 > 0)
	{
		ft_hexa_x(nbr / 16, num);
		ft_putchar_c(base[nbr % 16], num);
	}
	else
		ft_putchar_c(base[nbr], num);
}

void	ft_va(char letter, va_list args, int *num)
{
	if (letter == 's')
		ft_putstr_s(va_arg(args, char *), num);
	if (letter == 'd')
		ft_putnbr_d(va_arg(args, int), num);
	if (letter == 'x')
		ft_hexa_x(va_arg(args, unsigned int), num);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		c;
	int		num;

	c = 0;
	num = 0;
	va_start (args, str);
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
	va_end (args);
	return (num);
}

int	main(void)
{
	char	*str;
	int		num;
	int		another;

	str = "Unai";
	num = -2147483648;
	another = 1992492;
	printf("--- --- Tester --- ---\n");
	ft_printf("Hola buenas, %s\n", str);
	printf("Hola buenas, %s\n", str);
	ft_printf("Número: %d\n", num);
	printf("Número (bueno): %d\n", num);
	ft_printf("x: %x\n", another);
	printf("x (bueno): %x\n", another);
	return (0);
}
