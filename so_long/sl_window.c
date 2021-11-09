/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:04:03 by ullorent          #+#    #+#             */
/*   Updated: 2021/11/09 17:10:18 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_createwin(t_mdata cmap)
{
	char	*relative_path;
	int		num;
	t_wdata	win_data;

	relative_path = "./assets/grass-4.xpm";
	num = 10000;
	win_data.mlx = mlx_init();
	win_data.mlx_win = mlx_new_window(win_data.mlx, (int)cmap.map_x * 50,
			(int)cmap.map_y * 50, "./so_long");
	ft_replaceimg(&win_data, cmap);
	mlx_loop(win_data.mlx);
}

void	ft_replaceimg(t_wdata *win_data, t_mdata cmap)
{
	char	*ground_file;
	int		num;

	num = 50;
	ground_file = "./assets/grass-3.xpm";
	win_data->addr = mlx_xpm_file_to_image(win_data->mlx, ground_file, &num,
			&num);
	mlx_put_image_to_window(win_data->mlx, win_data->mlx_win, win_data->addr,
		(char)cmap.fmap[(int)cmap.map_x] * 50,
		(char)cmap.fmap[(int)cmap.map_y] * 50);
}
