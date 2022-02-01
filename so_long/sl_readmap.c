/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_readmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:51:52 by ullorent          #+#    #+#             */
/*   Updated: 2022/02/01 19:13:34 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_readmap(t_mdata	*cmap, char **argv)
{
	int		temp;

	cmap->fd = open(argv[1], O_RDONLY);
	if (cmap->fd == -1)
	{
		printf("Error\n");
		printf("The map could not be readed\n");
		exit(0);
	}
	cmap->map = malloc(1);
	if (!cmap->map)
		exit (0);
	cmap->map[0] = '\0';
	temp = 1;
	while (temp != (int)ft_strlen(cmap->map))
	{
		temp = ft_strlen(cmap->map);
		cmap->map = ft_strjoin_sl(cmap->map, get_next_line(cmap->fd));
	}
}

void	ft_cpy_map(t_mdata *cmap)
{
	int	i;
	int	c;

	i = 0;
	c = 1;
	cmap->map_y = 1;
	while (cmap->map[i] != '\0')
	{
		if (cmap->map[i] == '\n')
		{
			c++;
			cmap->map_y++;
		}
		i++;
	}
	cmap->fmap = (char **)malloc(sizeof(char *) * c + 1);
	cmap->fmap[1] = NULL;
	i = 0;
	while (i < c)
	{
		cmap->fmap[i] = ft_substr_gnl(&cmap->map, 0, ft_strn(cmap->map), 0);
		cmap->map = ft_substr(cmap->map, ft_strlen(cmap->fmap[i]) + 1,
				ft_strlen(cmap->map) - ft_strlen_gnl(cmap->fmap[i]));
		i++;
	}
}
