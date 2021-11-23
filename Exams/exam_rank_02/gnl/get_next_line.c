/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:37:21 by ullorent          #+#    #+#             */
/*   Updated: 2021/11/23 17:40:49 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	c;

	c = 0;
	while (str[c])
		c++;
	return (c);
}

int	check_ch(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n' || str[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_aux(char *line, char c)
{
	char	*str;
	int		i;

	i = 0;
	while (line[i])
		i++;
	str = (char *)malloc(2 + i);
	if (!str)
		return (NULL);
	i = 0;
	while (line[i])
	{
		str[i] = line[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
	free(line);
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
	while (!(check_ch(line)) && filed != 0)
	{
		filed = read(fd, &buff, 1);
		if (filed == 0)
		{
			if (line[0] == '\0')
			{
				free(line);
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

int	main(void)
{
	int		fd;
	int		line_count;
	char	*line;

	//printf("first: %p", line);
	line_count = 1;
	line = NULL;
	fd = open("file.txt", O_RDONLY);
	while (ft_strlen(line = get_next_line(fd)) > 0)
	{
		printf("  MAIN. Linea %d leída => %s", line_count, line);
		line_count++;
		//free(line);
	}
	//printf(" \n A line has been read #%d: %s", line_count++, line);
	//printf("\n");
	if (line == NULL)
		printf("-----------\n ERROR\n");
	else if (ft_strlen(line) == '0')
	{
		printf("-----------\n EOF has been reached\n");
			//free(line);
	}
	close(fd);
	return (0);
}
