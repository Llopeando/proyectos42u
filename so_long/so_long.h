/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:55:03 by ullorent          #+#    #+#             */
/*   Updated: 2021/11/11 13:43:33 by ullorent         ###   ########.fr       */
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
	void	*img;
	void	*mlx_win;
	void	*mlx;
	char	*addr;
	int		endian;
	int		img_width;
	int		img_height;
	int		pos_x;
	int		pos_y;
	int		x;
	int		y;
	int		col;
	int		moves;
	int		num;
	char	*path;
}				t_mdata;

/* --- map reading function(s) --- */
void	ft_readmap(t_mdata	*cmap, char *argv[]);
void	ft_cpy_map(t_mdata *cmap);

/* --- map image replace and render functions --- */
void	ft_createwin(t_mdata *cmap);
void	ft_replaceimg(t_mdata *cmap);
void	ft_ground_capem(t_mdata *cmap);

/* --- keyboard functions --- */
int		ft_move(int keyhook, t_mdata *cmap);
void	ft_movements_c(t_mdata *cmap);

/* --- keyboard functions (keys) --- */
void	ft_w_key(t_mdata *cmap);
void	ft_a_key(t_mdata *cmap);
void	ft_s_key(t_mdata *cmap);
void	ft_d_key(t_mdata *cmap);

/* --- other functions --- */
char	*ft_strjoin_sl(char const *s1, char const *s2);
// void	ft_sl_errors(t_mdata *cmap);

#endif