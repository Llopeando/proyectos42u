/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 12:16:17 by ullorent          #+#    #+#             */
/*   Updated: 2021/10/21 12:19:58 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int		ft_strnboo(const char *str);

size_t	ft_strlen(const char *str);
size_t	ft_strn(const char *str);

char	*ft_substr(char **s, unsigned int start, size_t len, int boo);
char	*ft_strjoin(char **s1, char **s2);
char	*get_next_line(int fd);
char	*ft_readline(int fd, char **temp);

void	ft_linefreemem(char **str);

#endif