/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_csp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:13:59 by ullorent          #+#    #+#             */
/*   Updated: 2021/09/29 16:36:07 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	c;

	c = 0;
	while (str[c] != '\0')
		c++;
	return (c);
}

void	ft_putchar(char c, int *num)
{
	write(1, &c, 1);
	(*num)++;
}

void	ft_putstr(char *str, int *num)
{
	if (!str)
		*num += write(1, "(null)", 6);
	else
		*num += write(1, str, ft_strlen(str));
}
