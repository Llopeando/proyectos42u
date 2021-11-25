/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:27:07 by ullorent          #+#    #+#             */
/*   Updated: 2021/11/24 18:44:40 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

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

void	ft_str(char *str, int *num)
{
	if (!str)
		num += write(1, "(null)", 6);
	else
		num += write(1, str, ft_strlen(str));
}

void	ft_dletter(long int n, int *num)
{
	if (n < 0)
	{
		ft_putchar_c('-', num);
		n *= -1;
	}
	if (n < 10)
	{
		ft_putchar_c(n + 48, num);
		return ;
	}
	else
		ft_dletter(n / 10, num);
	ft_dletter(n % 10, num);
}

void	ft_xletter(unsigned long int n, int *num)
{
	char	*base;

	base = "0123456789abcdef";
	if (n / 16 > 0)
	{
		ft_xletter(n / 16, num);
		ft_putchar_c(base[n % 16], num);
	}
	else
		ft_putchar_c(base[n], num);
}

void	ft_va(char letter, va_list args, int *num)
{
	if (letter == 's')
		ft_str(va_arg(args, char *), num);
	if (letter == 'd')
		ft_dletter(va_arg(args, long int), num);
	if (letter == 'x')
		ft_xletter(va_arg(args, unsigned int), num);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		num;
	int		c;

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

	str = "Unai";
	num = 25353535;
	ft_printf("Hola, me llamo %s\n", str);
	ft_printf("Hola, tu número es el %d\n", num);
	ft_printf("Hola, tus símbolos de memoria son %x\n", num);
	printf("Los números de memoria reales son %x\n", num);
	ft_printf("a\n");
	ft_printf(" ");
	return (0);
}
