/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:48:25 by ullorent          #+#    #+#             */
/*   Updated: 2021/10/08 12:49:50 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/stat.h>
#include <fcntl.h>

void	get_next_line(int fd)
{
	char	*buf;
	int		reading;
	int		c;

	c = 0;
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return ;
	printf("BUF = %s\n", buf);
	reading = read(fd, buf, BUFFER_SIZE);
	printf("Reading = %d\n", reading);
	while (buf[c] != '\0')
	{
		c++;
		if (c == '\n')
			printf("Ha encontrado el salto de línea");
	}
	buf[reading] = '\n';
	printf("Buf-text = %s\n", buf);
	return ;
}

int	main(void)
{
	int	fd;

	fd = open("file.txt", O_RDONLY);
	printf("FD = %d\n", fd);
	get_next_line(fd);
}
