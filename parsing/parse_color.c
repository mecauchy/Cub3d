#include "../includes/cub3d.h"



/*
	----- utiliser stock color de cette facon :

	if (line[0] == 'F')
		parse_color_line(line, &data->floor_color);
	else if (line[0] == 'C')
		parse_color_line(line, &data->ceiling_color);
*/

void	stock_color(char *line, t_color *color)
{
	char	**tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (*line == 'C' || *line == 'F' || *line == ' ')
		line++;
	tmp = ft_split(line, ',');
	while (tmp[i])
	{
		printf("%c\n", tmp[i][j]);
		if (tmp[i][j] == ' ')
			j++;
		while (is_digit(tmp[i][j]))
			j++;
		if (!is_digit(tmp[i][j]))
			exit_mess("colors must be in a range of 0-255");
		i++;
	}
	color->r = atoi(tmp[0]);
	color->g = atoi(tmp[1]);
	color->b = atoi(tmp[2]);
	free(tmp);
	check_limits(color);
}

void	parse_color(t_data *data, t_color *color)
{
	int	i = 0;

	if (data->line[i][0] == 'F')
		stock_color(data->line[i], color);
	// else if (data->line[0] == 'C')
	// 	stock_color(data->line, color);
}