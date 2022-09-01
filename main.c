/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 06:05:05 by hboukili          #+#    #+#             */
/*   Updated: 2022/08/30 21:34:02 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_convert(t_map *p, int x, int y)
{
	char	*str;

	x %= 50;
	y %= 50;
	if (p->dir == 1)
		str = p->cub.imgs[0].addr + (x * p->cub.imgs[0].line_length
				+ y * (p->cub.imgs[0].bits_per_pixel / 8));
	if (p->dir == 2)
		str = p->cub.imgs[1].addr + (x * p->cub.imgs[1].line_length
				+ y * (p->cub.imgs[1].bits_per_pixel / 8));
	if (p->dir == 3)
		str = p->cub.imgs[2].addr + (x * p->cub.imgs[2].line_length
				+ y * (p->cub.imgs[2].bits_per_pixel / 8));
	if (p->dir == 4)
		str = p->cub.imgs[3].addr + (x * p->cub.imgs[3].line_length
				+ y * (p->cub.imgs[3].bits_per_pixel / 8));
	return (*(int *)str);
}

void	ft_getdir(t_map *p, float a, float b)
{
	if (p->map[(int)((a - 1) / 50)][(int)b / 50] != '1')
		p->dir = 1;
	if (p->map[(int)((a + 1) / 50)][(int)b / 50] != '1')
		p->dir = 2;
	if (p->map[(int)a / 50][(int)((b - 1) / 50)] != '1')
		p->dir = 3;
	if (p->map[(int)a / 50][(int)((b + 1) / 50)] != '1')
		p->dir = 4;
}

t_map	*init_texture(t_map *p)
{
	int	z;

	p->cub.imgs = malloc(sizeof(t_data) * 4);
	p->cub.imgs[0].img = mlx_xpm_file_to_image(p->mlx, p->no, &z, &z);
	p->cub.imgs[0].addr = mlx_get_data_addr(p->cub.imgs[0].img,
			&p->cub.imgs[0].bits_per_pixel, &p->cub.imgs[0].line_length,
			&p->cub.imgs[0].endian);
	p->cub.imgs[1].img = mlx_xpm_file_to_image(p->mlx, p->ea, &z, &z);
	p->cub.imgs[1].addr = mlx_get_data_addr(p->cub.imgs[1].img,
			&p->cub.imgs[1].bits_per_pixel, &p->cub.imgs[1].line_length,
			&p->cub.imgs[1].endian);
	p->cub.imgs[2].img = mlx_xpm_file_to_image(p->mlx, p->so, &z, &z);
	p->cub.imgs[2].addr = mlx_get_data_addr(p->cub.imgs[2].img,
			&p->cub.imgs[2].bits_per_pixel, &p->cub.imgs[2].line_length,
			&p->cub.imgs[2].endian);
	p->cub.imgs[3].img = mlx_xpm_file_to_image(p->mlx, p->we, &z, &z);
	p->cub.imgs[3].addr = mlx_get_data_addr(p->cub.imgs[3].img,
			&p->cub.imgs[3].bits_per_pixel, &p->cub.imgs[3].line_length,
			&p->cub.imgs[3].endian);
	return (p);
}

void	init_cub(t_map *p)
{
	p->mlx = mlx_init();
	p->wind = mlx_new_window(p->mlx, 1920, 1080, "lol");
	p->img.img = mlx_new_image(p->mlx, 1920, 1080);
	p->img.addr = mlx_get_data_addr(p->img.img, &p->img.bits_per_pixel,
			&p->img.line_length, &p->img.endian);
	p = init_texture(p);
	ft_3d(p);
	mlx_hook(p->wind, 2, 1L << 0, ft_a, p);
	mlx_hook(p->wind, 3, 1L << 1, ft_b, p);
	mlx_loop_hook(p->mlx, move_player, p);
	mlx_hook(p->wind, 17, 0, ft_exit, p);
	mlx_loop(p->mlx);
}

int	main(int ac, char **av)
{
	char	**x;
	t_map	*p;
	int		i;

	if (ac == 2)
	{
		i = 0;
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
					p = init_p(p);
					init_cub(p);
				}
			}
		}
	}
	else
		write(1, "wrong number of argument\n", 26);
}
