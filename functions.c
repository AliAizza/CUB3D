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