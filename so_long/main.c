/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:09:12 by ullorent          #+#    #+#             */
/*   Updated: 2021/10/28 13:22:51 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_width;
	int		img_height;
}				t_data;

int	main(void)
{
	void	*mlx;
	char	*relative_path;
	void	*mlx_win;
	int		num;
	t_data	img;

	relative_path = "bicho.xpm";
	num = 10000;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "./so_long");
	img.addr = mlx_xpm_file_to_image(img.img, relative_path, &num,
			&num);
	if (img.addr == NULL)
		printf("no\n");
	mlx_put_image_to_window(mlx, mlx_win, img.addr, 100, 100);
	mlx_loop(mlx);
}
