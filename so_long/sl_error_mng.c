/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_error_mng.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 12:46:31 by ullorent          #+#    #+#             */
/*   Updated: 2021/11/17 12:47:45 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_pboomerror_lookup(t_ldata *map_l)
{
	if (map_l->p > 1 || map_l->p < 1)
	{
		printf("Error\n");
		printf("Map: There may be less than one start position or none\n");
		exit (0);
	}
	if (map_l->boo == 1)
	{
		printf("Error\n");
		printf("Map: The wall may not be complete\n");
		exit (0);
	}
}

void	ft_ecponem_lookup(t_mdata *cmap, t_ldata *map_l)
{
	if (cmap->fmap[map_l->y][map_l->x] == 'E')
		map_l->e++;
	if (cmap->fmap[map_l->y][map_l->x] == 'C')
		map_l->c++;
	if (cmap->fmap[map_l->y][map_l->x] == 'P')
		map_l->p++;
	if (cmap->fmap[map_l->y][map_l->x] != '1' && (map_l->x == 0
		|| map_l->x == cmap->map_x - 1 || map_l->y == 0
		|| map_l->y == cmap->map_y - 1))
		map_l->boo = 1;
}

void	ft_ecmerror_lookup(t_ldata *map_l)
{
	if (map_l->e != 1 || map_l->e > 1)
	{
		printf("Error\n");
		printf("Map: There may be more than one exit or none\n");
		exit (0);
	}
	if (map_l->c < 1)
	{
		printf("Error\n");
		printf("Map: There may be less than one collectable or none\n");
		exit (0);
	}
	return ;
}

void	ft_sl_errors(t_mdata *cmap, t_ldata *map_l)
{
	map_l->x = 0;
	map_l->y = 0;
	map_l->e = 0;
	map_l->c = 0;
	map_l->p = 0;
	map_l->boo = 0;
	while (map_l->y < cmap->map_y && map_l->x <= cmap->map_x)
	{
		if (cmap->fmap[map_l->y][map_l->x] == '\0')
		{
			map_l->x = 0;
			map_l->y++;
			if (map_l->y == cmap->map_y)
				break ;
		}
		ft_ecponem_lookup(cmap, map_l);
		map_l->x++;
	}
	ft_ecmerror_lookup(map_l);
	ft_pboomerror_lookup(map_l);
}
