/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizza <aaizza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 02:33:13 by hboukili          #+#    #+#             */
/*   Updated: 2022/08/31 22:38:40 by aaizza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_3d(t_map *p)
{
	t_norme	*t;

	t = malloc(sizeof(t_norme));
	t->x = 32;
	t->z = -1;
	while (++t->z < 1920)
	{
		t->h = p->player->x;
		t->g = p->player->y;
		t->i = t->h + (1000 * cos((p->player->angle + t->x) * M_PI / 180));
		t->j = t->g + (1000 * sin((p->player->angle + t->x) * M_PI / 180));
		ft_dda(t, p);
		if (t->x > -33)
			t->x -= (float)1 / (1920 / 50);
	}
	mlx_put_image_to_window(p->mlx, p->wind, p->img.img, 0, 0);
	free(t);
}

t_norme	*get_tnorme(t_norme *t)
{
	t->x0 = t->a / 50;
	t->y0 = t->b / 50;
	t->n = (t->a + t->xinc) / 50;
	t->s = (t->b + t->yinc) / 50;
	return (t);
}

t_norme	*init_dda(t_norme *t, t_map *p)
{
	p->player->x_distance = p->player->x;
	p->player->y_distance = p->player->y;
	t->dx = t->i - t->h;
	t->dy = t->j - t->g;
	if (abs(t->dx) > abs(t->dy))
		t->ab = abs(t->dx);
	else
		t->ab = abs(t->dy);
	t->xinc = t->dx / (float) t->ab;
	t->yinc = t->dy / (float) t->ab;
	t->a = t->h;
	t->b = t->g;
	return (t);
}

void	ft_dda(	t_norme *t, t_map *p)
{
	t_data	img;

	t = init_dda(t, p);
	while (p->map[(int)t->a / 50][(int)t->b / 50] != '1'
		&& p->map[(int)t->a / 50][(int)t->b / 50] != '\0'
	&& ft_betweenwalls(get_tnorme(t), p))
	{
		t->a += t->xinc;
		t->b += t->yinc;
		p->player->x_distance += t->xinc;
		p->player->y_distance += t->yinc;
	}
	ft_getdir(p, t->a, t->b);
	p->player->distance_to_wall = sqrt(pow((p->player->x_distance
					- p->player->x), 2)
			+ pow((p->player->y_distance - p->player->y), 2));
	t->c = (p->player->angle * M_PI / 180)
		- (((p->player->angle + t->x) * M_PI) / 180);
	if (t->c < 0)
		t->c += 2 * M_PI;
	if (t->c > 2 * M_PI)
		t->c -= 2 * M_PI;
	p->player->distance_to_wall = p->player->distance_to_wall * cos(t->c);
	t->wall = (50 * 1080) / p->player->distance_to_wall;
	draw_3d(p, t);
}
