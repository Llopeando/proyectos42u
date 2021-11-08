/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:26:40 by ullorent          #+#    #+#             */
/*   Updated: 2021/11/08 12:15:06 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_mdata	cmap;
	int		i;

	ft_readmap(&cmap);
	ft_cpy_map(&cmap);
	cmap.map_x = ft_strlen(cmap.fmap[0]);
	i = 0;
	while (cmap.fmap[i] != NULL)
	{
		printf("%s\n", cmap.fmap[i]);
		i++;
	}
	printf("\nx = %d\n", cmap.map_x);
	printf("y = %d\n", cmap.map_y);
	ft_createwin(cmap);
	printf("Ventana abierta correctamente\n");
	return (0);
}
