/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 04:20:12 by hboukili          #+#    #+#             */
/*   Updated: 2022/08/30 21:36:58 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_string(char **str, int i, int x)
{
	if (str[i][x] == '0' && (ft_strlen(str[i - 1]) < x
		|| ft_strlen(str[i + 1]) < x))
		return (0);
	if ((str[i][x] == '0' && str[i][x + 1] == 32))
		return (0);
	if ((str[i][x] == 32 && str[i][x + 1] == '0'))
		return (0);
	if ((str[i][x] == '0' && str[i + 1][x] == 32))
		return (0);
	if ((str[i][x] == '0' && str[i - 1][x] == 32))
		return (0);
	if (((str[i][x] == 'N' || str[i][x] == 'S' || str[i][x] == 'E'
		|| str[i][x] == 'W') && (str[i][x + 1] == 32)))
		return (0);
	if ((str[i][x] == 32 && ((str[i][x + 1] == 'N'
			|| str[i][x + 1] == 'S' || str[i][x + 1] == 'E'
			|| str[i][x + 1] == 'W'))))
		return (0);
	if ((((str[i][x] == 'N' || str[i][x] == 'S'
			|| str[i][x] == 'E' || str[i][x] == 'W')))
			&& (str[i + 1][x] == 32))
		return (0);
	return (1);
}

int	check_string2(char **str, int i, int x)
{
	if ((((str[i][x] == 'N' || str[i][x] == 'S'
			|| str[i][x] == 'E' || str[i][x] == 'W'))
				&& str[i - 1][x] == 32))
		return (0);
	if (str[i][x] != '1' && str[i][x] != '0' && str[i][x] != 'N'
		&& str[i][x] != 'S' && str[i][x] != 'E' && str[i][x] != 'W'
			&& str[i][x] != 32)
		return (0);
	return (1);
}

int	check_map2(char **str)
{
	int	i;
	int	c;
	int	x;

	i = -1;
	c = 0;
	while (str[++i])
	{
		x = -1;
		while (str[i][++x])
		{
			if (!check_string(str, i, x)
				|| !check_string2(str, i, x))
				return (0);
			if (str[i][x] == 'N' || str[i][x] == 'S'
				|| str[i][x] == 'E' || str[i][x] == 'W')
					c++;
		}
	}
	if (c != 1)
		return (0);
	return (1);
}

int	check_map(char **str)
{
	int	i;
	int	x;

	i = -1;
	while (str[0][++i])
		if (str[0][i] != ' ' && str[0][i] != '1')
			return (0);
	i = -1;
	while (str[++i])
	{
		x = -1;
		if (str[i][0] == '\0' || str[i][ft_strlen(str[i]) - 1] != '1')
			return (0);
		while (str[i][++x])
		{
			if (str[i][x] == ' ')
				x++;
			if (str[i][x] == '1')
				break ;
			if (str[i][x] != ' ' && str[i][x] != '1')
				return (0);
		}
	}
	return (1);
}

int	check_int(char *f)
{
	char	**i;
	int		x;

	i = ft_split(f, ',');
	x = 0;
	while (i[x])
	{
		if (ft_atoi(i[x]) > 255 || ft_atoi(i[x]) < 0)
			return (0);
		x++;
	}
	if (x != 3)
		return (0);
	x = -1;
	while (i[++x])
		free(i[x]);
	free(i);
	return (1);
}
