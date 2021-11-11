/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_keyboard_fct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 12:02:42 by ullorent          #+#    #+#             */
/*   Updated: 2021/11/11 12:17:16 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_w_key(t_mdata *cmap)
{
	char	*path;
	int		num;

	num = 50;
	if (cmap->fmap[cmap->pos_y][cmap->pos_x] == 'C')
	{
		cmap->col--;
		cmap->fmap[cmap->pos_y][cmap->pos_x] = '0';
	}
	path = "./assets/player-xmas.xpm";
	cmap->addr = mlx_xpm_file_to_image(cmap->mlx, path, &num, &num);
	mlx_put_image_to_window(cmap->mlx, cmap->mlx_win, cmap->addr,
		cmap->pos_x * 50, cmap->pos_y * 50 - 50);
	path = "./assets/grass-3.xpm";
	cmap->addr = mlx_xpm_file_to_image(cmap->mlx, path, &num, &num);
	mlx_put_image_to_window(cmap->mlx, cmap->mlx_win, cmap->addr,
		cmap->pos_x * 50, cmap->pos_y * 50);
	ft_movements_c(cmap);
	cmap->pos_y--;
}

void	ft_a_key(t_mdata *cmap)
{
	char	*path;
	int		num;

	num = 50;
	if (cmap->fmap[cmap->pos_y][cmap->pos_x] == 'C')
	{
		cmap->col--;
		cmap->fmap[cmap->pos_y][cmap->pos_x] = '0';
	}
	path = "./assets/player-xmas.xpm";
	cmap->addr = mlx_xpm_file_to_image(cmap->mlx, path, &num, &num);
	mlx_put_image_to_window(cmap->mlx, cmap->mlx_win, cmap->addr,
		cmap->pos_x * 50 - 50, cmap->pos_y * 50);
	path = "./assets/grass-3.xpm";
	cmap->addr = mlx_xpm_file_to_image(cmap->mlx, path, &num, &num);
	mlx_put_image_to_window(cmap->mlx, cmap->mlx_win, cmap->addr,
		cmap->pos_x * 50, cmap->pos_y * 50);
	ft_movements_c(cmap);
	cmap->pos_x--;
}

void	ft_s_key(t_mdata *cmap)
{
	char	*path;
	int		num;

	num = 50;
	if (cmap->fmap[cmap->pos_y][cmap->pos_x] == 'C')
	{
		cmap->col--;
		cmap->fmap[cmap->pos_y][cmap->pos_x] = '0';
	}
	path = "./assets/player-xmas.xpm";
	cmap->addr = mlx_xpm_file_to_image(cmap->mlx, path, &num, &num);
	mlx_put_image_to_window(cmap->mlx, cmap->mlx_win, cmap->addr,
		cmap->pos_x * 50, cmap->pos_y * 50 + 50);
	path = "./assets/grass-3.xpm";
	cmap->addr = mlx_xpm_file_to_image(cmap->mlx, path, &num, &num);
	mlx_put_image_to_window(cmap->mlx, cmap->mlx_win, cmap->addr,
		cmap->pos_x * 50, cmap->pos_y * 50);
	ft_movements_c(cmap);
	cmap->pos_y++;
}

void	ft_d_key(t_mdata *cmap)
{
	char	*path;
	int		num;

	num = 50;
	if (cmap->fmap[cmap->pos_y][cmap->pos_x] == 'C')
	{
		cmap->col--;
		cmap->fmap[cmap->pos_y][cmap->pos_x] = '0';
	}
	path = "./assets/player-xmas.xpm";
	cmap->addr = mlx_xpm_file_to_image(cmap->mlx, path, &num, &num);
	mlx_put_image_to_window(cmap->mlx, cmap->mlx_win, cmap->addr,
		cmap->pos_x * 50 + 50, cmap->pos_y * 50);
	path = "./assets/grass-3.xpm";
	cmap->addr = mlx_xpm_file_to_image(cmap->mlx, path, &num, &num);
	mlx_put_image_to_window(cmap->mlx, cmap->mlx_win, cmap->addr,
		cmap->pos_x * 50, cmap->pos_y * 50);
	ft_movements_c(cmap);
	cmap->pos_x++;
}