/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:09:12 by ullorent          #+#    #+#             */
/*   Updated: 2021/10/26 15:37:50 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_width;
	int		img_height;
}				t_data;

int main(void)
{
	void	*mlx;
	char	*relative_path = "bicho.xpm";
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 400, 400, "./so_long");
	//img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_xpm_file_to_image(img.img, relative_path, &img.img_width,
			&img.img_height);
	if (img.addr == NULL)
		printf("no\n");
	printf("pasa\n");
	mlx_put_image_to_window(mlx, mlx_win, img.addr, 0, 0);
	printf("pasa\n");
	mlx_loop(mlx);
}
