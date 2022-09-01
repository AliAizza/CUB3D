/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizza <aaizza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 02:31:47 by hboukili          #+#    #+#             */
/*   Updated: 2022/09/01 21:28:08 by aaizza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_3d(t_map *p, t_norme *t)
{
	int	i;
	int	tmp1;

	i = 0;
	while (i < 1080 && t->z < 1920)
	{
		if (i < (int)(1080 - t->wall) / 2)
			my_mlx_pixel_put(&p->img, t->z, i, p->cel);
		else if (i < (int)(((1080 - t->wall) / 2) + t->wall))
		{
			if (p->dir == 1 || p->dir == 2)
				p->eh = fmod(t->b / 50, 1);
			if (p->dir == 3 || p->dir == 4)
				p->eh = fmod(t->a / 50, 1);
			p->eh *= 50;
			my_mlx_pixel_put(&p->img, t->z, i,
				ft_convert(p, (int)(((i - ((1080 - t->wall)
									/ 2)) * 50) / t->wall), p->eh));
		}
		else
			my_mlx_pixel_put(&p->img, t->z, i, p->floor);
		i++;
	}
}

void	paint(t_map *p)
{
	t_norme	t;

	t.width = 0;
	t.i = -1;
	t.zero = mlx_xpm_file_to_image(p->mlx, "./xpm/0.xpm", &t.w, &t.h);
	t.walla = mlx_xpm_file_to_image(p->mlx, "./xpm/wall.xpm", &t.w, &t.h);
	t.player = mlx_xpm_file_to_image(p->mlx, "./xpm/player.xpm", &t.w, &t.h);
	while (p->map[++t.i])
	{
		t.n = -1;
		t.height = 0;
		while (p->map[t.i][++t.n])
		{
			if (p->map[t.i][t.n] == '0')
				mlx_put_image_to_window(p->mlx, p->wind, t.zero, p->mini
					* t.height, p->mini * t.width);
			if (p->map[t.i][t.n] == '1')
				mlx_put_image_to_window(p->mlx, p->wind, t.walla, p->mini
					* t.height, p->mini * t.width);
			t.height += 50;
		}
		t.width += 50;
	}
	draw_player(p);
}

void	draw_player(t_map *p)
{
	void	*t;
	int		i;
	int		j;

	t = mlx_xpm_file_to_image(p->mlx, "./xpm/player.xpm", &i, &j);
	mlx_put_image_to_window(p->mlx, p->wind, t, p->mini
		* (p->player->y - 5), p->mini * (p->player->x - 5));
}

int	ft_betweenwalls(t_norme *t, t_map *p)
{
	if (p->map[t->n][t->s] == ' ')
		return (0);
	if (p->map[t->n][t->s] == '0' && t->s > 0 && p->map[t->n][t->s - 1] == '1'
		&& p->map[t->n + 1][t->s]
	&& p->map[t->n + 1][t->s] == '1' && t->x0 == t->n + 1 && t->y0 == t->s - 1)
		return (0);
	else if (p->map[t->n][t->s] == '0' && p->map[t->n][t->s + 1] == '1'
	&& p->map[t->n - 1][t->s] == '1' && t->x0 == t->n - 1 && t->y0 == t->s + 1)
		return (0);
	else if (p->map[t->n][t->s] == '0' && p->map[t->n + 1][t->s] == '1'
	&& p->map[t->n][t->s + 1] == '1' && t->x0 == t->n + 1 && t->y0 == t->s + 1)
		return (0);
	else if (p->map[t->n][t->s] == '0' && p->map[t->n - 1][t->s] == '1'
	&& p->map[t->n][t->s - 1] == '1' && t->x0 == t->n - 1 && t->y0 == t->s - 1)
		return (0);
	return (1);
}
