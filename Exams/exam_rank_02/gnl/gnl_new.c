/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:26:56 by ullorent          #+#    #+#             */
/*   Updated: 2021/12/02 17:18:24 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int	check_ch(char *str)
{
	int	c;

	c = 0;
	if (!str)
		return (0);
	while (str[c])
	{
		if (str[c] == '\n' || str[c] == '\0')
			return (1);
		c++;
	}
	return (0);
}

char	*ft_aux(char *line, char i)
{
	char	*str;
	int		c;

	c = 0;
	while (line[c])
		c++;
	str = (char *)malloc(c + 2);
	if (!str)
		return (NULL);
	c = 0;
	while (line[c])
	{
		str[c] = line[c];
		c++;
	}
	str[c] = i;
	str[c + 1] = '\0';
	free (line);
	return (str);
}

char	*get_next_line(int fd)
{
	char	*line;
	int		filed;
	char	buff;

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
			free (line);
			return (NULL);
		}
		line = ft_aux(line, buff);
	}
	return (line);
}

int	main(void)
{
	char	*line;
	int		fd;
	int		boo;

	boo = 0;
	fd = open("file.txt", O_RDONLY);
	while (boo < 6)
	{
		line = get_next_line(fd);
		printf("%s", line);
		boo++;
	}
	return (0);
}
