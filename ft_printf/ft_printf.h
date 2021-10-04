/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 11:08:59 by ullorent          #+#    #+#             */
/*   Updated: 2021/10/01 12:35:26 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);

void	ft_va(char let, va_list args, int *num);

void	ft_putstr_s(char *str, int *num);
void	ft_putchar_c(char c, int *num);
size_t	ft_strlen(const char *str);

void	ft_putnbr_di(int n, int *num);
void	ft_putnbr_u(unsigned int n, int *num);

void	ft_hexa_x(unsigned long int nbr, int boo, int *num);

#endif