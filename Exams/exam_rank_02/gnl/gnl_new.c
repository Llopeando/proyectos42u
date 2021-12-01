/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:26:56 by ullorent          #+#    #+#             */
/*   Updated: 2021/12/01 18:03:48 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

int	check_ch(char *str)
{
	int	c;

	c = 0;
	if (!str)
		return (NULL);
	while (str[c])
	{
		if (str[c] == '\n' || str[c] == '\0')
			return (1);
		c++;
	}
	return (0);
}

char	*ft_aux(char *line, char c)
{
	char	*str;
	int		c;

	c = 0;
	while (line[c])
		c++;
	str = (char *)malloc(2 + c);
	if (!str)
		return (NULL);
	c = 0;
	while (line[c])
	{
		str[c] = line[c];
		c++;
	}
	str[c] = c;
	str[c + 1] = '\0';
	free(line);
	return (line);
}

char	*get_next_line(int fd)
{
	char	*line;
	char	buff;
	int		filed;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	filed = 1;
	while (!(check_ch(line)) && filed != 0)
	{
		filed = read(fd, &buff, 1);
		if (filed == 0)
		{
			if (line[0] == '\0')
			{
				free (line);
				return (NULL);
			}
			return (line);
		}
		if (filed < 0)
		{
			free(line);
			return (NULL);
		}
		line = ft_aux(line, buff);
	}
	return (line);
}
