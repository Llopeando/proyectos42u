/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 11:26:35 by ullorent          #+#    #+#             */
/*   Updated: 2021/10/01 12:45:50 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	ft_va(char let, va_list args, int *num)
{
	if (let == 'c')
		ft_putchar_c(va_arg(args, int), num);
	if (let == 's')
		ft_putstr_s(va_arg(args, char *), num);
	if (let == 'p')
	{
		*num += write(1, "0x", 2);
		ft_hexa_x(va_arg(args, unsigned long int), 0, num);
	}
	if (let == 'd' || let == 'i')
		ft_putnbr_di(va_arg(args, int), num);
	if (let == 'u')
		ft_putnbr_u(va_arg(args, unsigned int), num);
	if (let == 'x')
		ft_hexa_x(va_arg(args, unsigned int), 0, num);
	if (let == 'X')
		ft_hexa_x(va_arg(args, unsigned int), 1, num);
	if (let == '%')
		ft_putchar_c('%', num);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		num;

	i = 0;
	num = 0;
	va_start (args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			ft_va(str[i + 1], args, &num);
			i += 2;
			continue ;
		}
		ft_putchar_c(str[i], &num);
		i++;
	}
	va_end (args);
	return (num);
}
