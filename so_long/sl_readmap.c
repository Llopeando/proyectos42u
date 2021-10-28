/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_readmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:51:52 by ullorent          #+#    #+#             */
/*   Updated: 2021/10/28 14:19:36 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin_sl(char const *s1, char const *s2)
{
	size_t	c;
	size_t	i;
	char	*mem;

	c = 0;
	i = 0;
	if (!s1)
		return (0);
	if (!s2)
		return ((char *)s1);
	mem = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!mem)
		return (NULL);
	while (s1[c] != '\0')
	{
		*mem = s1[c];
		c++;
		mem++;
	}
	while (s2[i] != '\0')
	{
		*mem = s2[i];
		i++;
		mem++;
	}
	*mem = '\0';
	return (mem - c - i);
}

int	main(void)
{
	int		fd;
	int		temp;
	int		c;
	int		i;
	char	*map;
	char	**fmap;

	i = 0;
	fd = open("mapa.ber", O_RDONLY);
	if (fd == -1)
	{
		printf("Error\n");
		printf("The map could not be readed\n");
		return (0);
	}
	map = malloc(1);
	map[0] = '\0';
	temp = 1;
	while (temp != (int)ft_strlen(map))
	{
		temp = ft_strlen(map);
		map = ft_strjoin_sl(map, get_next_line(fd));
	}
	c = 1;
	while (map[i] != '\0')
	{
		if (map[i] == '\n')
			c++;
		i++;
	}
	fmap = (char **)malloc(sizeof(char *) * c + 1);
	fmap[1] = NULL;
	i = 0;
	while (i < c)
	{
		fmap[i] = ft_substr_gnl(&map, 0, ft_strn(map) + 1, 0);
		map = ft_substr_gnl(&map, ft_strlen_gnl(fmap[i]), ft_strlen_gnl(map)
				- ft_strlen_gnl(fmap[i]), 1);
		printf("%s", fmap[i]);
		i++;
	}
	return (0);
}
