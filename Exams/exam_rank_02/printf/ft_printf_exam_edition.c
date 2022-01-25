/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_exam_edition.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:27:07 by ullorent          #+#    #+#             */
/*   Updated: 2022/01/25 19:47:02 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
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

void	ft_d_func(int n, int *num)
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
		ft_d_func(n / 10, num);
	ft_d_func(n % 10, num);
}

void	ft_str_func(char *str, int *num)
{
	if (!str)
		*num += write(1, "(null)", 6);
	else
		*num += write(1, str, ft_strlen(str));
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

void	ft_va(char let, va_list args, int *num)
{
	if (let == 's')
		ft_str_func(va_arg(args, char *), num);
	if (let == 'd')
		ft_d_func(va_arg(args, int), num);
	if (let == 'x')
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

/* Main for testing purposes */
/* int	main(void)
{
	char	*str;
	int		num;

	str = "Unai";
	num = 25353535;
	ft_printf("Hola, me llamo %s\n", str);
	printf("Real -> string: %s\n", str);
	ft_printf("Hola, tu número es el %d\n", num);
	ft_printf("Hola, tus símbolos de memoria son %x\n", num);
	printf("Los números de memoria reales son %x\n", num);
	// ft_printf("a\n");
	// ft_printf(" ");
	return (0);
} */
