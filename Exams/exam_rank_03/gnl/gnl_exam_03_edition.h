/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_exam_03_edition.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:22:48 by ullorent          #+#    #+#             */
/*   Updated: 2022/03/24 17:37:47 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_EXAM_03_EDITION_H
# define GNL_EXAM_03_EDITION_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_aux(char *line, char buff);
int		ft_gnl_checker(char *line);

#endif