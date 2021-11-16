/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_error_mng.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 12:46:31 by ullorent          #+#    #+#             */
/*   Updated: 2021/11/16 17:46:33 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_lookup(t_mdata *cmap)
{
	t_ldata	map_l;

	while (cmap->map[map_l.count] == 'E')
	{
		map_l.e++;
		printf("Pasados\n");
	}
}

void	ft_sl_errors(t_mdata *cmap)
// gestionar error de mapa contando caracteeres; al menos un portal, al menos un coleccionable, al menos un personaje, que haya muros... etc
{
	t_ldata	map_l;
	int		x;
	int		y;

	x = 0;
	y = 0;
	map_l.count = 0;
	map_l.e = 0;
	map_l.c = 0;
	printf("\n--- GESTIÓN DE ERRORES (checker) ---\n");
	while (y < cmap->y && x < cmap->x)
	{
		while (cmap->fmap[y][x] == 'E' && (map_l.e < 1))
		{
			map_l.e++;
			printf("Tiene una salida: \033[0;32mOK\033[0m\n");
			printf("\033[0m");
		}
		while (cmap->fmap[y][x] == 'C' && (map_l.c <= 0))
		{
			map_l.c++;
			printf("Tiene un coleccionable: \033[0;32mOK\033[0m\n");
			printf("\033[0m");
		}
		if (cmap->fmap[y][x] == 'P')
		{
			map_l.p++;
			printf("Tiene un jugador: \033[0;32mOK\033[0m (%d)\n", map_l.p);
			printf("\033[0m");
		}
		if (cmap->fmap[y][x] == '\n')
		{
			y++;
			printf("y = %d\n", y);
		}
		x++;
		printf("pasa + 1: %d\n", x);
	}
	printf("%s\n", cmap->fmap[1]);
	if (map_l.e != 1 || map_l.e > 1)
	{
		printf("Tiene una salida: \033[0;31mKO\n");
		printf("\033[0m");
		// printf("Error\n");
		// printf("There may be more than one exit or none\n");
		printf("\n\033[0;31mError: \033[0m");
		printf("\033[0;33mVerifica el mapa que estás intentando cargar\033[0m\n");
		printf("--- --- --- --- ---- --- --- --- ---\n");
		exit (0);
	}
	if (map_l.c < 1)
	{
		printf("Tiene menos de un coleccionable: \033[0;31mKO\n");
		printf("\033[0m");
		// printf("Error\n");
		// printf("There may be less than one colectionable or none\n");
		printf("\n\033[0;31mError: \033[0m");
		printf("\033[0;33mVerifica el mapa que estás intentando cargar\033[0m\n");
		printf("\n\033[0;31mCHECKS FAIL\033[0m\n");
		printf("--- --- --- --- ---- --- --- --- ---\n");
		exit (0);
	}
	if (map_l.p > 1 || map_l.p < 1)
	{
		if (map_l.p > 1)
		{
			printf("Tiene más de un jugador: \033[0;31mKO\n");
			printf("\033[0m");
			// printf("Error\n");
			// printf("There may be less than one colectionable or none\n");
			printf("\n\033[0;31mError: \033[0m");
			printf("\033[0;33mVerifica el mapa que estás intentando cargar\033[0m\n");
			printf("\n\033[0;31mCHECKS FAIL\033[0m\n");
			printf("--- --- --- --- ---- --- --- --- ---\n");
			exit (0);
		}
		printf("No tiene un jugador: \033[0;31mKO\n");
		printf("\033[0m");
		// printf("Error\n");
		// printf("There may be less than one colectionable or none\n");
		printf("\n\033[0;31mError: \033[0m");
		printf("\033[0;33mVerifica el mapa que estás intentando cargar\033[0m\n");
		printf("\n\033[0;31mCHECKS FAIL\033[0m\n");
		printf("--- --- --- --- ---- --- --- --- ---\n");
		exit (0);
	}
	printf("\n\033[0;32mALL CHECKS OK\033[0m\n");
	printf("--- --- --- --- ---- --- --- --- ---\n");
	return ;
}
