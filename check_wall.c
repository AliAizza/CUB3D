/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 04:42:37 by hboukili          #+#    #+#             */
/*   Updated: 2022/08/30 06:09:32 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_checkwall(t_norme *t, t_map *p)
{
	t->n = t->a / 50;
	t->s = t->b / 50;
	if (p->map[t->n][t->s] == ' ' || p->map[t->n][t->s] == '1'
	|| p->map[t->n][t->s] == '\0' || !ft_betweenwalls(t, p))
	{
		free(t);
		return (0);
	}
	free(t);
	return (1);
}

t_norme	*helper(t_map *p, int i, t_norme *t)
{
	if (i == 2)
	{
		t->x0 = p->player->x / 50;
		t->y0 = p->player->y / 50;
		t->a = p->player->x + 5 * cos((90 + p->player->angle) * M_PI / 180);
		t->b = p->player->y + 5 * sin((90 + p->player->angle) * M_PI / 180);
	}
	else if (i == 3)
	{
		t->x0 = p->player->x / 50;
		t->y0 = p->player->y / 50;
		t->a = p->player->x - 5 * cos((90 + p->player->angle) * M_PI / 180);
		t->b = p->player->y - 5 * sin((90 + p->player->angle) * M_PI / 180);
	}
	return (t);
}

t_norme	*get_check_wall(t_map *p, int i)
{
	t_norme	*t;

	t = malloc(sizeof(t_norme));
	if (i == 0)
	{
		t->x0 = p->player->x / 50;
		t->y0 = p->player->y / 50;
		t->a = (p->player->x - (10 * cos(p->player->angle * M_PI / 180)));
		t->b = (p->player->y - (10 * sin(p->player->angle * M_PI / 180)));
	}
	else if (i == 1)
	{
		t->x0 = p->player->x / 50;
		t->y0 = p->player->y / 50;
		t->a = (p->player->x + (10 * cos(p->player->angle * M_PI / 180)));
		t->b = (p->player->y + (10 * sin(p->player->angle * M_PI / 180)));
	}
	else
		t = helper(p, i, t);
	return (t);
}
