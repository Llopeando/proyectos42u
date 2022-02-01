/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:04:03 by ullorent          #+#    #+#             */
/*   Updated: 2022/02/01 19:16:52 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putimage(t_mdata *cmap)
{
	int	num;

	cmap->path = "./assets/grass-3.xpm";
	if (cmap->fmap[cmap->y][cmap->x] == '1')
		cmap->path = "./assets/all-4.xpm";
	else if (cmap->fmap[cmap->y][cmap->x] == 'P')
	{
		cmap->path = "./assets/player-down.xpm";
		cmap->pos_x = cmap->x;
		cmap->pos_y = cmap->y;
	}
	else if (cmap->fmap[cmap->y][cmap->x] == 'C')
	{
		cmap->path = "./assets/coll-coin.xpm";
		cmap->col++;
	}
	else if (cmap->fmap[cmap->y][cmap->x] == 'E')
		cmap->path = "./assets/portal-1.xpm";
	num = 50;
	cmap->addr = mlx_xpm_file_to_image(cmap->mlx, cmap->path, &num, &num);
	mlx_put_image_to_window(cmap->mlx, cmap->mlx_win, cmap->addr,
		cmap->x * 50, cmap->y * 50);
}

void	ft_ground_capem(t_mdata *cmap)
{
	int	num;

	num = 50;
	cmap->path = "./assets/grass-3.xpm";
	cmap->addr = mlx_xpm_file_to_image(cmap->mlx, cmap->path,
			&num, &num);
	mlx_put_image_to_window(cmap->mlx, cmap->mlx_win, cmap->addr,
		cmap->x * 50, cmap->y * 50);
}

void	ft_createwin(t_mdata *cmap)
{
	int		num;

	num = 10000;
	cmap->mlx = mlx_init();
	cmap->mlx_win = mlx_new_window(cmap->mlx, cmap->map_x * 50,
			cmap->map_y * 50, "./so_long");
	ft_replaceimg(cmap);
}

void	ft_replaceimg(t_mdata *cmap)
{
	int	num;

	num = 50;
	cmap->col = 0;
	cmap->y = 0;
	while (cmap->fmap[cmap->y] != NULL)
	{
		cmap->x = 0;
		while (cmap->fmap[cmap->y][cmap->x] != '\0')
		{
			ft_ground_capem(cmap);
			if (cmap->fmap[cmap->y][cmap->x] == '1')
				ft_putimage(cmap);
			else if (cmap->fmap[cmap->y][cmap->x] == 'C')
				ft_putimage(cmap);
			else if (cmap->fmap[cmap->y][cmap->x] == 'P')
				ft_putimage(cmap);
			else if (cmap->fmap[cmap->y][cmap->x] == 'E')
				ft_putimage(cmap);
			cmap->x++;
		}
		cmap->y++;
	}
}
