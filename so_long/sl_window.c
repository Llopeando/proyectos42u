/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:04:03 by ullorent          #+#    #+#             */
/*   Updated: 2021/11/08 12:12:40 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_createwin(t_mdata cmap)
{
	void	*mlx;
	char	*relative_path;
	void	*mlx_win;
	int		num;
	t_wdata	win_data;

	relative_path = "bicho.xpm";
	num = 10000;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, cmap.map_x, cmap.map_y, "./so_long");
	win_data.addr = mlx_xpm_file_to_image(win_data.img, relative_path, &num,
			&num);
	if (win_data.addr == NULL)
		printf("no\n");
	mlx_put_image_to_window(mlx, mlx_win, win_data.addr, 100, 100);
	mlx_loop(mlx);
}
