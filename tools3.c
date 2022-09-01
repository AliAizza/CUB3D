/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:19:05 by hboukili          #+#    #+#             */
/*   Updated: 2022/08/30 02:28:50 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_s(char *str, char *str1, int i)
{
	if (str[i] + 1 != '\0' && str1[1] != '\0' && str[i + 1] == str1[1])
	{
		if (!str1[2])
			return (1);
		else if (str[i + 2] == str1[2])
			return (1);
		else
			return (0);
	}
	else if (!str1[1])
		return (1);
	else
		return (0);
}

int	ft_strcmp(char *str, char *str1)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		else if (str[i] != ' ' && str[i] == str1[0])
		{
			if (!ft_check_s(str, str1, i))
				return (0);
			else
				return (1);
		}
		else
			return (0);
	}
	return (0);
}

char	**ft_map2(char *new)
{
	char	**map;
	int		i;
	int		x;

	x = 0;
	i = -1;
	while (new[++i])
		if (new[i] == '\n')
			x++;
	map = malloc(sizeof(char *) * (x + 1 + 1));
	map[0] = ft_strdup("");
	i = -1;
	x = 0;
	while (new[++i])
	{
		if (new[i] == '\n')
			map[++x] = ft_strdup("");
		if (new[i] != '\n')
			map[x] = ft_charjoin(map[x], new[i]);
	}
	map[++x] = 0;
	return (map);
}

char	**ft_map(char *str)
{
	int		fd;
	char	*s;
	char	*new;
	char	**map;

	new = ft_strdup("");
	fd = open(str, O_RDONLY);
	s = get_next_line(fd);
	if (s == NULL)
		return (NULL);
	while (s)
	{
		new = ft_strjoin(new, s);
		free(s);
		s = get_next_line(fd);
	}
	map = ft_map2(new);
	free (new);
	return (map);
}

int	ft_exit(t_map *p)
{
	mlx_destroy_window(p->mlx, p->wind);
	exit(1);
	return (0);
}
