#include "../includes/cub3d.h"

int	is_digit(char *line)
{
	// int	i;
	int	nb;

	// i = 0;
	nb = atoi(line);
	if (nb >= 0 && nb <= 255)
		return (1);
	return (0);
}

int	check_limits(t_color *color)
{
	if (color->r >= 0 && color->r <= 255 && color->g >= 0 && color->g <= 255 && color->b >= 0 && color->b <= 255)
		return (1);
	return (0);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	is_only_space(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if(str[i] == ' ')
			i++;
	}
	if (len == i)
		return (1);
	return (0);
}