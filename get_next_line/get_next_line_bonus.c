/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 12:15:31 by ullorent          #+#    #+#             */
/*   Updated: 2021/11/08 13:50:33 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <sys/stat.h>
#include <fcntl.h>

void	ft_linefreemem(char **str)
{
	if (str != NULL && *str != NULL)
	{
		free (*str);
		*str = NULL;
	}
}

size_t	ft_strlen(const char *str)
{
	size_t	c;

	c = 0;
	if (!str)
		return (0);
	while (str[c] != '\0')
		c++;
	return (c);
}

char	*ft_readline(int fd, char **temp)
{
	char	*buf;
	int		reading;

	reading = 1;
	buf = NULL;
	while ((ft_strnboo(*temp) && reading > 0))
	{
		buf = malloc(BUFFER_SIZE + 1);
		reading = read(fd, buf, BUFFER_SIZE);
		buf[reading] = '\0';
		if (reading == -1 || (reading == 0 && !(*temp))
			|| (reading == 0 && (*temp)[0] == '\0'))
		{
			ft_linefreemem(&buf);
			ft_linefreemem(temp);
			return (NULL);
		}
		*temp = ft_strjoin(temp, &buf);
	}
	return (*temp);
}

char	*get_next_line(int fd)
{
	static char	*temp[4096];
	char		*final;

	temp[fd] = ft_readline(fd, &temp[fd]);
	final = ft_substr(&temp[fd], 0, ft_strn(temp[fd]) + 1, 0);
	temp[fd] = ft_substr(&temp[fd], ft_strlen(final), ft_strlen(temp[fd])
			- ft_strlen(final), 1);
	return (final);
}
