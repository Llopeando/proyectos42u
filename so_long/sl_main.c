/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:26:40 by ullorent          #+#    #+#             */
/*   Updated: 2021/11/11 13:48:27 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_fread(char *file)
{
	int	file_len;

	file_len = ft_strlen(file);
	printf("File len = %d\n", file_len);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mdata	cmap;

	if (argc != 2)
	{
		printf("Insufficient arguments\n");
		exit (1);
	}
	// if (ft_fread(argv[1]) == 0)
	// 	printf("Invalid argument\n");
	ft_readmap(&cmap, argv);
	// ft_sl_errors(&cmap);
	ft_cpy_map(&cmap);
	cmap.map_x = ft_strlen(cmap.fmap[0]);
	ft_createwin(&cmap);
	cmap.moves = 0;
	mlx_hook(cmap.mlx_win, 2, 1L << 0, ft_move, &cmap);
	mlx_loop(cmap.mlx);
	return (0);
}
