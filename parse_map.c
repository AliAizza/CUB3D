/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 02:47:39 by hboukili          #+#    #+#             */
/*   Updated: 2022/08/30 21:31:51 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map	*parse_map2(t_map *map, char **x, t_m m)
{
	int	i;
	int	n;

	map->no = ft_substr(x[m.no], ft_getstr(x[m.no], "NO "),
			ft_strlen(x[m.no]) - ft_getstr(x[m.no], "NO "));
	map->so = ft_substr(x[m.so], ft_getstr(x[m.so], "SO "),
			ft_strlen(x[m.so]) - ft_getstr(x[m.so], "SO "));
	map->we = ft_substr(x[m.we], ft_getstr(x[m.we], "WE "),
			ft_strlen(x[m.we]) - ft_getstr(x[m.we], "WE "));
	map->ea = ft_substr(x[m.ea], ft_getstr(x[m.ea], "EA "),
			ft_strlen(x[m.ea]) - ft_getstr(x[m.ea], "EA "));
	map->f = ft_substr(x[m.f], ft_getstr(x[m.f], "F "),
			ft_strlen(x[m.f]) - ft_getstr(x[m.f], "F "));
	map->c = ft_substr(x[m.c], ft_getstr(x[m.c], "C "),
			ft_strlen(x[m.c]) - ft_getstr(x[m.c], "C "));
	map->map = malloc(sizeof(char *) * (map_len(x, m.m) + 1));
	i = m.m - 1;
	n = 0;
	while (x[++i])
		map->map[n++] = ft_strdup(x[i]);
	map->map[n] = 0;
	return (map);
}

void	parse_map1(t_map *map)
{
	int	i;
	int	n;

	i = -1;
	n = 0;
	while (map->f[++i])
		if (map->f[i] == ',')
			n++;
	i = -1;
	while (map->c[++i])
		if (map->c[i] == ',')
			n++;
	if (n != 4 || !check_int(map->f) || !check_int(map->c))
	{
		write(2, "Error in map\n", 14);
		exit(0);
	}
}

t_map	*parse_map(char **x)
{
	t_map	*map;
	t_m		m;

	map = malloc(sizeof(t_map));
	m.no = ft_search(x, "NO ");
	m.so = ft_search(x, "SO ");
	m.we = ft_search(x, "WE ");
	m.ea = ft_search(x, "EA ");
	m.f = ft_search(x, "F ");
	m.c = ft_search(x, "C ");
	m.m = ft_search(x, "1");
	m.m0 = ft_search(x, "0");
	if (!check_errors(m) || !check_f(x, m.m))
	{
		write(2, "Error in map\n", 14);
		exit(0);
	}
	map = parse_map2(map, x, m);
	if (!check_map(map->map) || !check_map2(map->map) || !check_texture(map))
	{
		write(2, "Error in map\n", 14);
		exit(0);
	}
	parse_map1(map);
	return (map);
}

int	check_errors(t_m m)
{
	if (m.no == -1 || m.so == -1 || m.we == -1
		|| m.ea == -1 || m.f == -1 || m.c == -1)
	{
		write(2, "Error in map\n", 14);
		exit(0);
	}
	if (m.no > m.m || m.so > m.m || m.we > m.m
		|| m.ea > m.m || m.f > m.m || m.c > m.m)
	{
		write(2, "Error in map\n", 14);
		exit (0);
	}
	if (m.m0 != -1)
	{
		write(2, "Error in map\n", 14);
		exit(0);
	}
	return (1);
}

int	check_name(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == '.')
			break ;
	if (str[i + 1] == 'c')
		if (str[i + 2] == 'u')
			if (str[i + 3] == 'b')
				if (!str[i + 4])
					return (1);
	return (0);
}
