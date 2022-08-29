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
    float x;
    float y;
    float angle;
    float x_distance;
    float y_distance;
    float distance_to_wall;
} t_player;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_pic
{
    t_data *imgs;
}   t_pic;


typedef struct map
{
    int i;
    int j;
    void *mlx;
    void *wind;
    char **map;
    char *no;
    char *so;
    char *we;
    char *ea;
    char *f;
    t_pic cub;
    char *c;
    t_player *player;
    unsigned long cel;
    unsigned long floor;
    t_data  img;
    int map_height;
    int map_width;
    int event[6];
    int k;
    int dir;
    float eh;
} t_map;

typedef struct map_int
{
    int no;
	int so;
	int we;
	int ea;
	int m;
    int f;
    int c;
    int m0;
} t_m;


void	paint(t_map *p);
void    ft_3d(t_map *p);
char	**ft_split(char *s, char c);
char	*ft_strdup(char *s1);
char	*ft_charjoin(char *s1, char s2);
int     check_map(char **str);
t_map	*parse_map(char **x);
int     check_name(char *str);
int     check_errors(t_m m);    
int     ft_getstr(char *str, char *a);
int     ft_search(char **x, char *str);
int	    check_f(char **str, int m);
int     map_len(char **map, int x);
#endif