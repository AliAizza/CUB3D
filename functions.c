/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 04:20:41 by hboukili          #+#    #+#             */
/*   Updated: 2022/08/23 05:25:38 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strdup(char *s1)
{
	char	*ptr;
	int		len;
	int		i;

	len = ft_strlen(s1);
	ptr = malloc (len + 1 * sizeof(char));
	i = 0;
	if (ptr == NULL)
		return (0);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_charjoin(char *s1, char s2)
{
	char	*new;
	int		i;
	int		a;

	a = ft_strlen(s1);
	new = malloc(a + 2);
	if (!new)
		return (NULL);
	i = 0;
	while (i < a)
	{
		new[i] = s1[i];
		i++;
	}
	new[i++] = s2;
	new[i] = '\0';
	free (s1);
	return (new);
}

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

int	get_point(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
			return (i);
		i++;
	}
	return (-1);
}

int	ft_search(char **x, char *str)
{
	int	i;

	i = 0;
	while (x[i])
	{
		if (ft_strcmp(x[i], str))
			return (i);
		i++;
	}
	return (-1);
}
