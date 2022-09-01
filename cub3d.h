/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 04:34:13 by hboukili          #+#    #+#             */
/*   Updated: 2022/08/30 06:09:13 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "./getnext_line/get_next_line.h"
# include <mlx.h>
# include <math.h>

typedef struct player
{
	float	x;
	float	y;
	float	angle;
	float	x_distance;
	float	y_distance;
	float	distance_to_wall;
}	t_player;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_pic
{
	t_data	*imgs;
}	t_pic;

typedef struct norme
{
	int		i;
	int		j;
	int		y;
	void	*walla;
	void	*zero;
	void	*player;
	int		h;
	int		g;
	float	proj;
	float	x;
	int		z;
	int		dx;
	int		dy;
	int		ab;
	float	xinc;
	float	yinc;
	float	a;
	int		wall;
	float	b;
	float	c;
	int		x0;
	int		y0;
	int		n;
	int		w;
	int		s;
	int		height;
	int		width;
}	t_norme;

typedef struct map
{
	int				i;
	int				j;
	void			*mlx;
	void			*wind;
	char			**map;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*f;
	t_pic			cub;
	float			mini;
	char			*c;
	t_player		*player;
	unsigned long	cel;
	unsigned long	floor;
	t_data			img;
	int				map_height;
	int				map_width;
	int				event[6];
	int				k;
	int				dir;
	float			eh;
}	t_map;

typedef struct map_int
{
	int	no;
	int	so;
	int	we;
	int	ea;
	int	m;
	int	f;
	int	c;
	int	m0;
}	t_m;

int				check_int(char *f);
int				check_map(char **str);
t_map			*parse_map2(t_map *map, char **x, t_m m);
void			parse_map1(t_map *map);
t_map			*parse_map(char **x);
int				check_errors(t_m m);
int				check_name(char *str);
int				check_map2(char **str);
int				check_string2(char **str, int i, int x);
int				check_string(char **str, int i, int x);
int				ft_strcmp(char *str, char *str1);
char			**ft_map2(char *new);
char			**ft_map(char *str);
int				ft_exit(t_map *p);
int				ft_getstr(char *str, char *a);
int				ft_a(int keycode, t_map *p);
int				ft_b(int keycode, t_map *p);
t_map			*init_p(t_map *p);
int				window_witdh(char **map, char a);
int				map_len(char **map, int x);
int				check_f(char **str, int m);
int				check_texture(t_map *p);
char			*ft_strdup(char *s1);
char			*ft_charjoin(char *s1, char s2);
int				ft_atoi(char *str);
int				get_point(char *str);
int				ft_search(char **x, char *str);
char			**ft_split(char *s, char c);
t_player		*ft_player(t_map *p);
t_map			*check_player(t_map *p, int i, int j);
char			**remove_player(t_map *p);
unsigned long	ft_rgb(t_map *p, char c);
void			ft_3d(t_map *p);
void			paint(t_map *p);
void			paint(t_map *p);
void			draw_player(t_map *p);
void			ft_3d(t_map *p);
void			ft_getdir(t_map *p, float a, float b);
int				ft_convert(t_map *p, int x, int y);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			ft_dda(	t_norme *t, t_map *p);
int				ft_betweenwalls(t_norme *t, t_map *p);
int				ft_checkwall(t_norme *t, t_map *p);
void			draw_3d(t_map *p, t_norme *t);
int				ft_checkwall(t_norme *t, t_map *p);
t_norme			*get_check_wall(t_map *p, int i);
int				move_player(t_map *p);
#endif