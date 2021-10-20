/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:48:50 by ullorent          #+#    #+#             */
/*   Updated: 2021/10/19 17:03:20 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

size_t	ft_strlen(const char *str);
size_t	ft_strn(const char *str);
int		ft_strnboo(const char *str);

char	*ft_substr(char **s, unsigned int start, size_t len, int boo);
char	*ft_strjoin(char **s1, char **s2);

char	*get_next_line(int fd);
char	*ft_readline(int fd, char *temp);

void	ft_freejoinmem(char **s1, char **s2);

#endif