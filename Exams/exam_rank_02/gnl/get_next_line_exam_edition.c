/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_exam_edition.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:15:10 by ullorent          #+#    #+#             */
/*   Updated: 2022/01/25 19:46:47 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_exam_edition.h"

int	ft_gnl_checker(char *line)
{
	int	c;

	c = 0;
	if (!line)
		return (0);
	while (line[c])
	{
		if (line[c] == '\0' || line[c] == '\n')
			return (1);
		c++;
	}
	return (0);
}

char	*ft_aux(char *line, char buff)
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
	str[c] = buff;
	str[c + 1] = '\0';
	free (line);
	return (str);
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
	while (!(ft_gnl_checker(line) && filed != 0))
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

/* Main for testing purposes */
/* int	main(void)
{
	char	*line;
	int		fd;

	fd = open("file.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("line = %s\n", line);
	return (0);
} */
