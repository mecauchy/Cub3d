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