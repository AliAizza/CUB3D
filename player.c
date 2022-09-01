/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 02:07:46 by hboukili          #+#    #+#             */
/*   Updated: 2022/08/30 05:59:55 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_player	*ft_player(t_map *p)
{
	t_norme		i;
	t_player	*player;

	player = malloc (sizeof(t_player));
	i.i = -1;
	i.n = 0;
	while (p->map[++i.i])
	{
		i.j = -1;
		i.y = 0;
		while (p->map[i.i][++i.j])
		{
			if (p->map[i.i][i.j] == 'N' || p->map[i.i][i.j] == 'S'
				|| p->map[i.i][i.j] == 'W' || p->map[i.i][i.j] == 'E')
			{
				player->x = i.n + 20;
				player->y = i.y + 20;
			}
			i.y += 50;
		}
		i.n += 50;
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
			p = check_player(p, i, j);
			j++;
		}
		i++;
	}
	return (p->map);
}

t_map	*check_player(t_map *p, int i, int j)
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
	return (p);
}

void	move2(t_map *p)
{
	if (p->event[4] == 1)
	{
		if (ft_checkwall(get_check_wall(p, 2), p))
		{
			p->player->x += 5 * cos((90 + p->player->angle) * M_PI / 180);
			p->player->y += 5 * sin((90 + p->player->angle) * M_PI / 180);
		}
	}
	if (p->event[5] == 1)
	{
		if (ft_checkwall(get_check_wall(p, 3), p))
		{
			p->player->x -= 5 * cos((90 + p->player->angle) * M_PI / 180);
			p->player->y -= 5 * sin((90 + p->player->angle) * M_PI / 180);
		}
	}
	ft_3d(p);
	if (p->k == 1)
		paint(p);
}

int	move_player(t_map *p)
{
	if (p->event[0] == 1)
		p->player->angle += 5;
	if (p->event[1] == 1)
		p->player->angle -= 5;
	if (p->event[2] == 1)
	{
		if (ft_checkwall(get_check_wall(p, 0), p))
		{
			p->player->x -= 10 * cos(p->player->angle * (M_PI / 180));
			p->player->y -= 10 * sin(p->player->angle * (M_PI / 180));
		}
	}
	if (p->event[3] == 1)
	{
		if (ft_checkwall(get_check_wall(p, 1), p))
		{
			p->player->x += 10 * cos(p->player->angle * M_PI / 180);
			p->player->y += 10 * sin(p->player->angle * M_PI / 180);
		}
	}
	move2(p);
	return (0);
}
