/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 11:54:48 by ullorent          #+#    #+#             */
/*   Updated: 2021/08/05 13:09:50 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_strncmp(const char *str1, const char *str2, size_t n);
int				ft_atoi(const char *str);

char			*ft_strchr(const char *str, int c);
char			*ft_strrchr(const char *str, int c);

void			*ft_memset(void *b, int c, size_t len);

void			ft_bzero(void *s, size_t n);

size_t			ft_strlen(const char *str);
size_t			ft_strlcpy(char *dst, const char *src, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t n);

#endif