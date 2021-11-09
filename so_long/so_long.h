/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:55:03 by ullorent          #+#    #+#             */
/*   Updated: 2021/11/09 17:09:25 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include <stdio.h>
# include <mlx.h>

/* --- structures --- */
typedef struct rdmap_data {
	int		fd;
	int		map_x;
	int		map_y;
	char	*map;
	char	**fmap;
}				t_mdata;

typedef struct win_data {
	void	*img;
	void	*mlx_win;
	void	*mlx;
	char	*addr;
	int		endian;
	int		img_width;
	int		img_height;
}				t_wdata;

/* --- map reading function(s) --- */
void	ft_readmap(t_mdata	*cmap);
void	ft_cpy_map(t_mdata *cmap);

/* --- map image replace and render functions --- */
void	ft_createwin(t_mdata cmap);
void	ft_replaceimg(t_wdata *win_data, t_mdata cmap);

/* --- keyboard functions --- */

/* --- game mechanics functions --- */

/* --- other functions --- */
char	*ft_strjoin_sl(char const *s1, char const *s2);

#endif