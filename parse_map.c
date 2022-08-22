/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 02:47:39 by hboukili          #+#    #+#             */
/*   Updated: 2022/08/07 23:58:37 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_atoi(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (-1);
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}

int check_map(char **str)
{
	int i = -1;
	int x;
	while(str[0][++i])
		if(str[0][i] != ' ' && str[0][i] != '1')
			return(0);
	i = -1;
	while(str[++i])
	{
		x = -1;
		if (str[i][0] == '\0')
			return (0);
		while(str[i][++x])
		{
			if(str[i][x] == ' ')
				x++;
			if (str[i][x] == '1')
				break ; 
			if (str[i][x] != ' ' && str[i][x] != '1')
				return (0);
		}
		if(str[i][ft_strlen(str[i]) - 1] != '1')
			return (0);
	}
	i = -1;
	int c = 0;
	while(str[++i])
	{
		x = -1;
		while(str[i][++x])
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
			if ((str[i][x] == 32 && ((str[i][x + 1] == 'N' || str[i][x + 1] == 'S'
				|| str[i][x + 1] == 'E' || str[i][x + 1] == 'W'))))
				return (0);
			if ((((str[i][x] == 'N' || str[i][x] == 'S'
				|| str[i][x] == 'E' || str[i][x] == 'W'))) && (str[i + 1][x] == 32))
				return (0);
			if ((((str[i][x] == 'N' || str[i][x] == 'S'
				|| str[i][x] == 'E' || str[i][x] == 'W'))&& str[i - 1][x] == 32))
				return (0);
			if (str[i][x] != '1' && str[i][x] != '0' && str[i][x] != 'N'
				&& str[i][x] != 'S' && str[i][x] != 'E' && str[i][x] != 'W'
					&& str[i][x] != 32)
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

int	check_int(char *f)
{
	char **i;

	i = ft_split(f, ',');
	int x = 0;
	while(i[x])
	{
		if (ft_atoi(i[x]) > 255 || ft_atoi(i[x]) < 0)
			return (0);
		x++;
	}
	return (1);
}

t_map	*parse_map(char **x)
{
	t_map 	*map;
	t_m		m;
	int		i;
	map = malloc(sizeof(t_map));
	m.no = ft_search(x, "NO ");
	m.so = ft_search(x, "SO ");
	m.we = ft_search(x, "WE ");
	m.ea = ft_search(x, "EA ");
	m.f = ft_search(x, "F ");
	m.c = ft_search(x, "C ");
	m.m = ft_search(x, "1");
	m.m0 = ft_search(x, "0");
	if(!check_errors(m) || !check_f(x, m.m))
	{
		free(map);
		return (NULL);
	}
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
	int n = 0;
	while(x[++i])
		map->map[n++] = ft_strdup(x[i]);
	map->map[n] = 0;
	if (!check_map(map->map))
	{
		write(2, "Error in map\n", 14);
		//free();
		return (NULL);
	}
    i = -1;
    n = 0;
    while(map->f[++i])
        if(map->f[i] == ',')
            n++;
    i = -1;
    while(map->c[++i])
        if(map->c[i] == ',')
            n++;
    if (n != 4)
    {
        write(2, "Error in map\n", 14);
		//free();
		return (NULL);
    }
	if (!check_int(map->f) || !check_int(map->c))
	{
        write(2, "Error in map\n", 14);
		//free();
		return (NULL);
	}
	return (map);
}
