/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 05:02:39 by hboukili          #+#    #+#             */
/*   Updated: 2022/08/30 04:41:14 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_getstr(char *str, char *a)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != a[0]
			&& str[i] != a[1])
			return (i);
		i++;
	}
	return (0);
}

int	ft_a(int keycode, t_map *p)
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

int	ft_b(int keycode, t_map *p)
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

t_map	*init_p(t_map *p)
{
	int	i;
	int	z;

	i = -1;
	p->mini = 0.2;
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
	while (p->map[++i])
		if (z < ft_strlen(p->map[i]))
			z = ft_strlen(p->map[i]);
	p->map_height = z;
	p->map_width = i;
	return (p);
}

unsigned long	ft_rgb(t_map *p, char c)
{
	char	**str;
	int		r;
	int		g;
	int		b;

	if (c == 'c')
		str = ft_split(p->c, ',');
	else
		str = ft_split(p->f, ',');
	r = atoi(str[0]);
	free(str[0]);
	g = atoi(str[1]);
	free(str[1]);
	b = atoi(str[2]);
	free(str[2]);
	free(str);
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}
