/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:48:25 by ullorent          #+#    #+#             */
/*   Updated: 2021/10/21 18:23:11 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
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
	char		*buf;
	static int	reading;

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
	static char	*temp;
	char		*final;

	temp = ft_readline(fd, &temp);
	final = ft_substr(&temp, 0, ft_strn(temp) + 1, 0);
	temp = ft_substr(&temp, ft_strlen(final), ft_strlen(temp)
			- ft_strlen(final), 1);
	return (final);
}
