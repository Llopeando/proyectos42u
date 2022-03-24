/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_exam_03_edition.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:52:27 by ullorent          #+#    #+#             */
/*   Updated: 2022/03/24 16:37:34 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

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

void	ft_strfunc(char *str, int *num)
{
	if (!str)
		*num += write (1, "(null)", 6);
	else
		*num += write(1, str, ft_strlen(str));
}

void	ft_numfunc(int n, int *num)
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
		ft_numfunc(n / 10, num);
	ft_numfunc(n % 10, num);
}

void	ft_hexaxfunc(unsigned long int nbr, int *num)
{
	char	*base;

	base = "0123456789abcdef";
	if (nbr / 16 > 0)
	{
		ft_hexaxfunc(nbr / 16, num);
		ft_putchar_c(base[nbr % 16], num);
	}
	else
		ft_putchar_c(base[nbr], num);
}

void	ft_va(char	letter, va_list args, int *num)
{
	if (letter == 's')
		ft_strfunc(va_arg(args, char *), num);
	if (letter == 'd')
		ft_numfunc(va_arg(args, int), num);
	if (letter == 'x')
		ft_hexaxfunc(va_arg(args, unsigned int), num);
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
	va_end(args);
	return (num);
}

/* --- Main for testing purposes --- */
/*int	main(void)
{
	char	*str;
	int		num;

	str = "Hola buenas";
	num = 1000000;
	ft_printf("%x\n", str);
	return (0);
}*/
