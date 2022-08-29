#include "cub3d.h"

float mini = 0.2;

int check_name(char *str)
{
    int i;

	i = -1;
    while(str[++i])
        if (str[i] == '.')
            break;
    if (str[i + 1] == 'c')
        if (str[i + 2] == 'u')
            if (str[i + 3] == 'b')
                if (!str[i + 4])
					return(1);
	return (0);
}

char **ft_map(char *str)
{
	int		fd;
	char	*s;
	char	*new;
	char	**map = NULL;

	new = ft_strdup("");
	fd = open(str, O_RDONLY);
	s = get_next_line(fd);
	if (s == NULL)
		return (NULL);
	while(s)
	{
		new = ft_strjoin(new, s);
		free(s);
		s = get_next_line(fd);
	}
	int i = 0;
	int x = 0;
	while(new[i])
	{
		if (new[i] == '\n')
			x++;
		i++;
	}
	map = malloc(sizeof(char *) * (x + 1 + 1));
	map[0] = ft_strdup("");
	i = -1;
	x = 0;
	while(new[++i])
	{
		if (new[i] == '\n')
			map[++x] = ft_strdup("");
		if (new[i] != '\n')
			map[x] = ft_charjoin(map[x], new[i]);
	}
	map[++x] = 0;
	free (new);
	return (map);
}

int get_point(char *str)
{
	int i = 0;
	while(str[i])
	{
		if (str[i] == '.')
			return (i);
		i++;
	}
	return (-1);
}
int ft_strcmp(char *str, char *str1)
{
	int i = 0;
	while(str[i])
	{
		if(str[i] == ' ')
			i++;
		else if (str[i] != ' ' && str[i] == str1[0])
		{
			if (str[i] + 1 != '\0' && str1[1] != '\0' && str[i + 1] == str1[1])
			{
				if (!str1[2])
					return (1);
				else if (str[i + 2] == str1[2])
					return (1);
				else
					return (0);
			}
			else if (!str1[1])
				return (1);
			else
				return (0);
		}
		else
			return (0);
	}
	return (0);
}

int	ft_search(char **x, char *str)
{
	int i = 0;

	while(x[i])
	{
		if (ft_strcmp(x[i], str))
			return (i);
		i++;
	}
	return (-1);
}

int check_errors(t_m m)
{
	if (m.no == -1 || m.so == -1 || m.we == -1
		|| m.ea == -1 || m.f == -1 || m.c == -1)
	{
		write(2, "Error in map\n", 14);
		return (0);
	}
	if (m.no > m.m || m.so > m.m || m.we > m.m
		|| m.ea > m.m || m.f > m.m || m.c > m.m)
	{
		write(2, "Error in map\n", 14);
		return (0);
	}
	if (m.m0 != -1)
	{
		write(2, "Error in map\n", 14);
		return (0);
	}
	return (1);
}

int ft_getstr(char *str, char *a)
{
	int i = 0;
	while(str[i])
	{
		if (str[i] != ' ' && str[i] != a[0]
			&& str[i] != a[1])
				return (i);
		i++;
	}
	return (0);
}

int	check_f(char **str, int m)
{
	int i = 0;
	int x;
	int l = 0;
	while(i < m)
	{
		x = 0;
		if (str[i][0] != '\0')
			l++;
		i++;
	}
	if (l != 6)
	{
		write(2, "Error in map\n", 14);
		return (0);
	}
	return (1);
}

int	map_len(char **map, int x)
{
	int i = 0;
	while(map[x])
	{
		i++;
		x++;
	}
	return (i);
}


int	window_witdh(char **map, char a)
{
	int	i;
	int j;
	int x;

	i = 0;
	x = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (x < j)
			x = j;
		i++;
	}
	if (a == 'w')
		return (x * 50);
	else
		return (i * 50);
}

int ft_betweenwalls(int x0, int y0, int x, int y, t_map *p)
{
	if (p->map[x][y] == ' ')
		return (0);
	if (p->map[x][y] == '0' && y > 0 && p->map[x][y - 1] == '1' && p->map[x + 1][y] && p->map[x + 1][y] == '1' && x0 == x + 1 && y0 == y - 1)
		return (0);
	else if (p->map[x][y] == '0' && p->map[x][y + 1] == '1' && p->map[x - 1][y] == '1' && x0 == x - 1 && y0 == y + 1)
		return (0);
	else if (p->map[x][y] == '0' && p->map[x + 1][y] == '1' && p->map[x][y + 1] == '1' && x0 == x + 1 && y0 == y + 1)
	 	return (0);
	else if (p->map[x][y] == '0' && p->map[x - 1][y] == '1' && p->map[x][y - 1] == '1' && x0 == x - 1 && y0 == y - 1)
		return (0);
	return (1);
}

int	ft_checkwall(int x0, int y0, float x, float y, t_map *p)
{
	int	x1;
	int	y1;

	x1 = x / 50;
	y1 = y / 50;
	if (p->map[x1][y1] == ' ' || p->map[x1][y1] == '1' || p->map[x1][y1] == '\0' || !ft_betweenwalls(x0, y0, x1, y1, p))
		return (0);
	return (1);
}

int	ft_a(int keycode, t_map* p)
{
	if (keycode == 123)
		p->event[0] = 1;
	if (keycode == 124)
		p->event[1] = 1;
	if (keycode == 1 || keycode == 125)
		p->event[2] = 1;
	if (keycode == 13 || keycode == 126)
		p->event[3] = 1;
	if (keycode == 0)
		p->event[4] = 1;
	if (keycode == 2)
		p->event[5] = 1;
	if (keycode == 53)
	{
		mlx_destroy_window(p->mlx, p->wind);
		exit(1);
	}
	if (keycode == 35)
		p->k = 1;
	return (0);
}

int ft_b(int keycode, t_map* p)
{
	if (keycode == 123)
		p->event[0] = 0;
	if (keycode == 124)
		p->event[1] = 0;
	if (keycode == 1 || keycode == 125)
		p->event[2] = 0;
	if (keycode == 13 || keycode == 126)
		p->event[3] = 0;
	if (keycode == 0)
		p->event[4] = 0;
	if (keycode == 2)
		p->event[5] = 0;
	if (keycode == 35)
		p->k = 0;
	return (0);
}

int	move_player(t_map *p)
{
	if (p->event[0] == 1)
		p->player->angle += 5;
	if (p->event[1] == 1)
		p->player->angle -= 5;
	if (p->event[2] == 1) 			//back
	{
		if (ft_checkwall(p->player->x / 50, p->player->y / 50, (p->player->x - (10 * cos(p->player->angle * M_PI / 180))), (p->player->y - (10 * sin(p->player->angle * M_PI / 180))), p))
		{
			p->player->x -= 10 * cos(p->player->angle * (M_PI / 180));
			p->player->y -= 10 * sin(p->player->angle * (M_PI / 180));
		}
	}
	if (p->event[3] == 1)  	//forward
	{
		if (ft_checkwall(p->player->x / 50, p->player->y / 50, (p->player->x + (10 * cos(p->player->angle * M_PI / 180))), (p->player->y + (10 * sin(p->player->angle * M_PI / 180))), p))
		{
			p->player->x += 10 * cos(p->player->angle * M_PI / 180);
			p->player->y += 10 * sin(p->player->angle * M_PI / 180);
		}
	}
	if (p->event[4] == 1)		//left
	{
		if (ft_checkwall(p->player->x / 50, p->player->y / 50, p->player->x + 5 * cos((90 + p->player->angle) * M_PI / 180), p->player->y + 5 * sin((90 + p->player->angle) * M_PI / 180), p))
		{
			p->player->x += 5 * cos((90 + p->player->angle) * M_PI / 180);
			p->player->y += 5 * sin((90 + p->player->angle) * M_PI / 180);
		}
	}
	if (p->event[5] == 1)		//right
	{
		if (ft_checkwall(p->player->x / 50, p->player->y / 50, p->player->x - 5 * cos((90 + p->player->angle) * M_PI / 180), p->player->y - 5 * sin((90 + p->player->angle) * M_PI / 180), p))
		{
			p->player->x -= 5 * cos((90 + p->player->angle) * M_PI / 180);
			p->player->y -= 5 * sin((90 + p->player->angle) * M_PI / 180);
		}
	}
	ft_3d(p);
	if (p->k == 1)
		paint(p);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int ft_convert(t_map *p, int x, int y)
{
	char *str;

	x %= 50;
	y %= 50;
	if (p->dir == 1)
		str = p->cub.imgs[0].addr + (x * p->cub.imgs[0].line_length + y * (p->cub.imgs[0].bits_per_pixel / 8));
	if (p->dir == 2)
		str = p->cub.imgs[1].addr + (x * p->cub.imgs[1].line_length + y * (p->cub.imgs[1].bits_per_pixel / 8));
	if (p->dir == 3)
		str = p->cub.imgs[2].addr + (x * p->cub.imgs[2].line_length + y * (p->cub.imgs[2].bits_per_pixel / 8));
	if (p->dir == 4)
		str = p->cub.imgs[3].addr + (x * p->cub.imgs[3].line_length + y * (p->cub.imgs[3].bits_per_pixel / 8));
	return (*(int *)str);
}

void	draw_3d(t_map *p, int wall, int z, float a, float b)
{
	int i;
	int tmp1;

	i = 0;
	while (i < 1080 && z < 1920)
	{
		if (i < (int)(1080 - wall) / 2)
			my_mlx_pixel_put(&p->img, z, i, p->cel);
		else if (i < (int)(((1080 - wall) / 2) + wall))
		{
			//my_mlx_pixel_put(&p->img, z, i, 0xFFFFFF);
			if (p->dir == 1 || p->dir == 2)
				p->eh = fmod(b / 50, 1);
			if (p->dir == 3 || p->dir == 4)
				p->eh = fmod(a / 50, 1);
			p->eh *= 50;
			my_mlx_pixel_put(&p->img, z, i, ft_convert(p, (int)(((i - ((1080 - wall) / 2)) * 50) / wall), p->eh));
		}
		else
			my_mlx_pixel_put(&p->img, z, i, p->floor);
		i++;
	}
	// cel
	// tmp1 = (1080 / 2) - (wall / 2);
	// while (i < tmp1)
	// {
	// 	my_mlx_pixel_put(&p->img, z, i, 0x0000FF);
	// 	i++;
	// }
	
	// // wall
	// tmp1 = (1080 / 2) + (wall / 2); 
	// while (i < tmp1)
	// {
	// 	my_mlx_pixel_put(&p->img, z, i, 0xFFFFFF);
	// 	i++;
	// }
	
	// // floor
	// while (i < 1080)
	// {
	// 	my_mlx_pixel_put(&p->img, z, i, 0xFF0000);
	// 	i++;
	// }
}

void	ft_getdir(t_map *p, float a, float b, float xinc, float yinc)
{
	if (p->map[(int)((a - 1)/ 50)][(int)b / 50] != '1')
		p->dir = 1;
	if (p->map[(int)((a + 1)/ 50)][(int)b / 50] != '1')
		p->dir = 2;
	if (p->map[(int)a / 50][(int)((b - 1)/ 50)] != '1')
		p->dir = 3;
	if (p->map[(int)a / 50][(int)((b + 1)/ 50)] != '1')
		p->dir = 4;
}

void	ft_dda(int x0, int y0, int x1, int y1, t_map *p, int x, int z)
{
	int		dx;
	int		dy;
	int		ab;
	float	xinc;
	float	yinc;
	float	a;
	// int		i;
	float wall;
	float	b;
	float	c;
	t_data	img;

	p->player->x_distance = p->player->x;
	p->player->y_distance = p->player->y;
	dx = x1 - x0;
	dy = y1 - y0;
	if (abs(dx) > abs(dy))
		ab = abs(dx);
	else
		ab = abs(dy);
	xinc = dx / (float) ab;
	yinc = dy / (float) ab;
	// i = 0;
	a = x0;
	b = y0;
	while (p->map[(int)a / 50][(int)b / 50] != '1' && p->map[(int)a / 50][(int)b / 50] != '\0' && ft_betweenwalls(a / 50, b / 50, (a + xinc) / 50, (b + yinc) / 50, p))
	{
		//mlx_pixel_put(p->mlx, p->wind, mini * b, mini * a, 0xFFFF00);
		//my_mlx_pixel_put(&p->img, b, a, 0xFFFF00);
		a += xinc;
		b += yinc;
		p->player->x_distance += xinc;
		p->player->y_distance += yinc;
		// i++;
	}
	ft_getdir(p, a, b, xinc, yinc);
	p->player->distance_to_wall = sqrt(pow((p->player->x_distance - p->player->x), 2) + pow((p->player->y_distance - p->player->y), 2));
	c = (p->player->angle * M_PI / 180) - (((p->player->angle + x) * M_PI) / 180);
	if (c < 0)
		c += 2 * M_PI;
	if (c > 2 * M_PI)
		c -= 2 * M_PI;
	p->player->distance_to_wall = p->player->distance_to_wall * cos(c);
	wall = (50 * 1080) / p->player->distance_to_wall;
	draw_3d(p, wall, z, a, b);
}


void	ft_3d(t_map *p)
{
	int i;
	int j;
	int	a;
	int	b;
	float proj;
	float x;
	int z;

	x = 32;
	z = -1;
	while (++z < 1920)
	{
		a = p->player->x;
		b = p->player->y;
		i = a + (1000 * cos((p->player->angle + x) * M_PI / 180));
		j = b + (1000 * sin((p->player->angle + x) * M_PI / 180));
		ft_dda(a, b, i, j, p, x, z);
		if (x > -33)
			x -= (float)1 / (1920 / 50);
	}
	mlx_put_image_to_window(p->mlx, p->wind, p->img.img, 0, 0);
}

void	draw_player(t_map *p)
{
	void	*t;
	int		i;
	int		j;

	t = mlx_xpm_file_to_image(p->mlx, "./player.xpm", &i, &j);
	mlx_put_image_to_window(p->mlx, p->wind, t, mini * (p->player->y - 5), mini * (p->player->x - 5));
}

void	paint(t_map *p)
{
	int i;
	int x;
	void	*wall;
	void	*zero;
	void	*player;
	int w;
	int h;
	int height;
	int width = 0;
	i = 0;
	zero = mlx_xpm_file_to_image(p->mlx, "./0.xpm", &w, &h);
	wall = mlx_xpm_file_to_image(p->mlx, "./wall.xpm", &w, &h);
	player = mlx_xpm_file_to_image(p->mlx, "./player.xpm", &w, &h);
	while(p->map[i])
	{
		x = 0;
		height = 0;
		while (p->map[i][x])
		{
			if (p->map[i][x] == '0')
				mlx_put_image_to_window(p->mlx, p->wind, zero, mini * height, mini * width);
			if (p->map[i][x] == '1')
				mlx_put_image_to_window(p->mlx, p->wind, wall, mini * height, mini * width);
			x++;
			height+=50;
		}
		width+=50;
		i++;
	}
	draw_player(p);
}

t_player	*ft_player(t_map *p)
{
	int i;
	int j;
	int x;
	int y;
	t_player *player;

	player = malloc (sizeof(t_player));
	i = 0;
	x = 0;
	while (p->map[i])
	{
		j = 0;
		y = 0;
		while (p->map[i][j])
		{
			if (p->map[i][j] == 'N' || p->map[i][j] == 'S' || p->map[i][j] == 'W' || p->map[i][j] == 'E')
			{
				player->x = x + 20;
				player->y = y + 20;
			}
			j++;
			y += 50;
		}
		i++;
		x += 50;
	}
	return (player);
}

char	**remove_player(t_map *p)
{
	int	i;
	int	j;

	i = 0;
	while (p->map[i])
	{
		j = 0;
		while (p->map[i][j])
		{
			if (p->map[i][j] == 'N')
			{
				p->player->angle = 175;
				p->map[i][j] = '0';
			}
			else if (p->map[i][j] == 'S')
			{
				p->player->angle = -5;
				p->map[i][j] = '0';
			}
			else if (p->map[i][j] == 'E')
			{
				p->player->angle = 85;
				p->map[i][j] = '0';
			}
			else if (p->map[i][j] == 'W')
			{
				p->player->angle = 265;
				p->map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
	return (p->map);
}

int	ft_exit(t_map *p)
{
	mlx_destroy_window(p->mlx, p->wind);
	exit(1);
	return (0);
}

unsigned long ft_rgb(t_map *p, char c)
{
	char **str;
	int r;
	int g;
	int b;

	if (c == 'c')
		str = ft_split(p->c, ',');
	else
		str = ft_split(p->f, ',');
	r = atoi(str[0]);
	g = atoi(str[1]);
	b = atoi(str[2]);
    return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

int main(int ac, char **av)
{
    char **x;
	t_map *p;

	int i = 0;
	int z;

	if (ac == 2)
	{
		if (!check_name(av[1]))
			write(2, "Error : .cub not found\n", 24);
		else
		{
			x = ft_map(av[1]);
			if (x != NULL)
			{
				p = parse_map(x);
				if (p != NULL)
				{
					p->player = ft_player(p);
					p->map = remove_player(p);
					p->floor = ft_rgb(p, 'f');
					p->cel = ft_rgb(p, 'c');
					p->event[0] = 0;
					p->event[1] = 0;
					p->event[2] = 0;
					p->event[3] = 0;
					p->event[4] = 0;
					p->event[5] = 0;
					p->k = 0;
					z = ft_strlen(p->map[0]);
					while(p->map[i])
					{
						if (z < ft_strlen(p->map[i]))
							z = ft_strlen(p->map[i]);
						i++;
					}
					p->map_height = z;
					p->map_width = i;
					p->mlx = mlx_init();
					p->wind = mlx_new_window(p->mlx, 1920, 1080, "lol");
					p->img.img = mlx_new_image(p->mlx, 1920, 1080);
					p->img.addr = mlx_get_data_addr(p->img.img, &p->img.bits_per_pixel, &p->img.line_length, &p->img.endian);
					p->cub.imgs = malloc(sizeof(t_data) * 4);
					p->cub.imgs[0].img = mlx_xpm_file_to_image(p->mlx, "onepiece.xpm", &z, &z);
					p->cub.imgs[0].addr = mlx_get_data_addr(p->cub.imgs[0].img, &p->cub.imgs[0].bits_per_pixel, &p->cub.imgs[0].line_length, &p->cub.imgs[0].endian);
					p->cub.imgs[1].img = mlx_xpm_file_to_image(p->mlx, "texture1.xpm", &z, &z);
					p->cub.imgs[1].addr = mlx_get_data_addr(p->cub.imgs[1].img, &p->cub.imgs[1].bits_per_pixel, &p->cub.imgs[1].line_length, &p->cub.imgs[1].endian);
					p->cub.imgs[2].img = mlx_xpm_file_to_image(p->mlx, "texture2.xpm", &z, &z);
					p->cub.imgs[2].addr = mlx_get_data_addr(p->cub.imgs[2].img, &p->cub.imgs[2].bits_per_pixel, &p->cub.imgs[2].line_length, &p->cub.imgs[2].endian);
					p->cub.imgs[3].img = mlx_xpm_file_to_image(p->mlx, "texture3.xpm", &z, &z);
					p->cub.imgs[3].addr = mlx_get_data_addr(p->cub.imgs[3].img, &p->cub.imgs[3].bits_per_pixel, &p->cub.imgs[3].line_length, &p->cub.imgs[3].endian);
					//ft_3d(p);
					mlx_hook(p->wind, 2, 1L << 0, ft_a, p);
					mlx_hook(p->wind, 3, 1L << 1, ft_b, p);
					mlx_loop_hook(p->mlx, move_player, p);
					mlx_hook(p->wind, 17, 0, ft_exit, p);
					mlx_loop(p->mlx);
				}
			}
		}
	}
	else
		write(1, "wrong number of argument\n", 26);
}
