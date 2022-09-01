/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 04:48:53 by hboukili          #+#    #+#             */
/*   Updated: 2022/08/30 06:01:08 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	window_witdh(char **map, char a)
{
	int	i;
	int	j;
	int	x;

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

int	map_len(char **map, int x)
{
	int	i;

	i = 0;
	while (map[x])
	{
		i++;
		x++;
	}
	return (i);
}

int	check_f(char **str, int m)
{
	int	i;
	int	x;
	int	l;

	i = 0;
	x = 0;
	l = 0;
	while (i < m)
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

int	check_texture(t_map *p)
{
	int	fd1;
	int	fd2;
	int	fd3;
	int	fd4;

	fd1 = open(p->no, O_RDONLY);
	fd2 = open(p->so, O_RDONLY);
	fd3 = open(p->we, O_RDONLY);
	fd4 = open(p->ea, O_RDONLY);
	if (fd1 == -1 || fd2 == -1
		|| fd3 == -1 || fd4 == -1)
		return (0);
	return (1);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
