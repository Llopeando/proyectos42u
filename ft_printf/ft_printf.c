/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 11:26:35 by ullorent          #+#    #+#             */
/*   Updated: 2021/09/29 16:38:47 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_va(char let, va_list args, int *num)
{
	if (let == 'c')
		ft_putchar((va_arg(args, int)), num);
	if (let == 's')
		ft_putstr((va_arg(args, char *)), num);
	/*if (let == 'p')
	if (let == 'd')
	if (let == 'i')
	if (let == 'u')
	if (let == 'x')
	if (let == 'X')
	if (let == '%')*/
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
		ft_putchar(str[i], &num);
		i++;
	}
	va_end (args);
	return (num);
}

/*int	main(void)
{
	char	*str;
	int		i;

	str = NULL;
	i = ft_printf("%s\n", str);
	printf("i == %d\n", i);
	i = printf("%s\n", str);
	printf("i == %d\n", i);
}*/
