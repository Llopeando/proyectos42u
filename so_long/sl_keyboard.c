/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_keyboard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:34:36 by ullorent          #+#    #+#             */
/*   Updated: 2021/11/17 14:00:49 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_movements_c(t_mdata *cmap)
{
	cmap->moves++;
	printf("Movements: %d\n", cmap->moves);
}

int	ft_close(t_mdata *cmap)
{
	mlx_destroy_window(cmap->mlx, cmap->mlx_win);
	mlx_destroy_image(cmap->mlx, cmap->addr);
	exit(0);
	return (0);
}

int	ft_move(int keyhook, t_mdata *cmap)
{
	int		num;

	num = 50;
	if (keyhook == 53)
		ft_close(cmap);
	if (cmap->col <= 0
		&& ((keyhook == 2 && cmap->fmap[cmap->pos_y][cmap->pos_x + 1] == 'E')
		|| (keyhook == 1 && cmap->fmap[cmap->pos_y + 1][cmap->pos_x] == 'E')
		|| (keyhook == 0 && cmap->fmap[cmap->pos_y][cmap->pos_x - 1] == 'E')
		|| (keyhook == 13 && cmap->fmap[cmap->pos_y - 1][cmap->pos_x] == 'E')))
		ft_close(cmap);
	if (keyhook == 13 && cmap->fmap[cmap->pos_y - 1][cmap->pos_x] != '1' &&
		cmap->fmap[cmap->pos_y - 1][cmap->pos_x] != 'E')
		ft_w_key(cmap);
	else if (keyhook == 0 && cmap->fmap[cmap->pos_y][cmap->pos_x - 1] != '1' &&
		cmap->fmap[cmap->pos_y][cmap->pos_x - 1] != 'E')
		ft_a_key(cmap);
	else if (keyhook == 1 && cmap->fmap[cmap->pos_y + 1][cmap->pos_x] != '1' &&
		cmap->fmap[cmap->pos_y + 1][cmap->pos_x] != 'E')
		ft_s_key(cmap);
	else if (keyhook == 2 && cmap->fmap[cmap->pos_y][cmap->pos_x + 1] != '1' &&
		cmap->fmap[cmap->pos_y][cmap->pos_x + 1] != 'E')
		ft_d_key(cmap);
	return (0);
}
