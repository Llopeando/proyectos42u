/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 11:08:59 by ullorent          #+#    #+#             */
/*   Updated: 2021/09/29 16:15:55 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);

void	ft_va(char let, va_list args, int *num);

void	ft_putstr(char *str, int *num);
void	ft_putchar(char c, int *num);
size_t	ft_strlen(const char *str);

#endif