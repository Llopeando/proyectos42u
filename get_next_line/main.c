/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 11:11:56 by ecamara           #+#    #+#             */
/*   Updated: 2021/10/07 12:29:01 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int		fd2;
	int		line_count;
	char	*line;

	line_count = 1;
	line = NULL;
	fd = open("file.txt", O_RDONLY);
	fd2 = open("file.txt", O_RDONLY);
	printf("fd: %d\n", fd);
	printf("fd-2: %d\n", fd2);
	//line = get_next_line(fd);
	//printf("final : [%s]", line);
	//printf("line: [%s]", get_next_line(fd));
	//printf("line: [%s]", get_next_line(fd));/*
	/*printf("line: [%s]", get_next_line(fd));*/
	/*printf("line: [%s]", get_next_line(fd));
	printf("line: [%s]", get_next_line(fd));
	printf("line: [%s]", get_next_line(fd));
	printf("line: [%s]", get_next_line(fd));
	printf("line: [%s]", get_next_line(fd));
	printf("line: [%s]", get_next_line(fd));
	printf("line: [%s]", get_next_line(fd));*/
	/*while	(ft_strlen(line = get_next_line(fd)) > 0)
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
	}*/
	close(fd);
	return (0);
}
