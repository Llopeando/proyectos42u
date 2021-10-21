/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 11:11:56 by ecamara           #+#    #+#             */
/*   Updated: 2021/10/21 12:03:01 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int		line_count;
	char	*line;

	line_count = 1;
	line = NULL;
	fd = open("file.txt", O_RDONLY);
	while (ft_strlen(line = get_next_line(fd)) > 0)
	{
		printf("  MAIN. Linea %d leída => %s", line_count, line);
		line_count++;
	}
	if (line == NULL)
		printf("-----------\n ERROR\n");
	else if (ft_strlen(line) == '0')
		printf("-----------\n EOF has been reached\n");
	close(fd);
	return (0);
}
