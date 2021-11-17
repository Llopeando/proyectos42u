/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:55:03 by ullorent          #+#    #+#             */
/*   Updated: 2021/11/17 13:36:09 by ullorent         ###   ########.fr       */
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

typedef struct rlmap_data {
	int		x;
	int		y;
	int		e;
	int		c;
	int		p;
	int		one;
	int		boo;
}				t_ldata;

/* --- map reading function(s) --- */
void	ft_readmap(t_mdata	*cmap, char *argv[]);
void	ft_cpy_map(t_mdata *cmap);

/* --- map image replace and render functions --- */
void	ft_createwin(t_mdata *cmap);
void	ft_replaceimg(t_mdata *cmap);
void	ft_ground_capem(t_mdata *cmap);

/* --- keyboard functions --- */
int		ft_move(int keyhook, t_mdata *cmap);
int		ft_close(t_mdata *cmap);
void	ft_movements_c(t_mdata *cmap);

/* --- keyboard functions (keys) --- */
void	ft_w_key(t_mdata *cmap);
void	ft_a_key(t_mdata *cmap);
void	ft_s_key(t_mdata *cmap);
void	ft_d_key(t_mdata *cmap);

/* --- error checking functions --- */
void	ft_sl_errors(t_mdata *cmap, t_ldata *map_l);
void	ft_pboomerror_lookup(t_ldata *map_l);
void	ft_ecmerror_lookup(t_ldata *map_l);
void	ft_sl_merrorcheck(t_ldata *map_l);

/* --- other functions --- */
char	*ft_strjoin_sl(char const *s1, char const *s2);
void	ft_argcm_check(int argc);
int		ft_fread(char *file);

#endif