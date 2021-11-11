/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:26:40 by ullorent          #+#    #+#             */
/*   Updated: 2021/11/11 16:31:07 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_fread(char *file)
{
	int		file_len;
	int		c;
	char	ext_check;

	c = 0;
	file_len = ft_strlen(file);
	ext_check = ((char)ft_strrchr(file, '.ber'));
	if (!ext_check)
	{
		printf("Error on main (reading file)\n");
		printf("The file extension or type, is invalid.\n");
		return (0);
	}
	if (file == 0)
	{
		printf("Error on main (reading file)\n");
		printf("The file coould not be found or could not be readed.\n");
	}
	if (file_len < 5)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_mdata	cmap;

	if (ft_fread(argv[1]) == 0)
		exit (1);
	if (argc < 2)
	{
		printf("Error on main (executing command)\n");
		printf("Insufficient arguments!\n");
		exit (1);
	}
	if (argc > 2)
	{
		printf("Error on main (executing command)\n");
		printf("Too many arguments!\n");
		exit (1);
	}
	ft_readmap(&cmap, argv);
	ft_cpy_map(&cmap);
	cmap.map_x = ft_strlen(cmap.fmap[0]);
	ft_createwin(&cmap);
	cmap.moves = 0;
	mlx_hook(cmap.mlx_win, 2, 1L << 0, ft_move, &cmap);
	mlx_loop(cmap.mlx);
	return (0);
}
