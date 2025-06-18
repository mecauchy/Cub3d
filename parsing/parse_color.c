#include "../includes/cub3d.h"
#include <string.h>


/*
	----- utiliser stock color de cette facon :

	if (line[0] == 'F')
		parse_color_line(line, &data->floor_color);
	else if (line[0] == 'C')
		parse_color_line(line, &data->ceiling_color);
*/

void	checker_line(char *line)
{
	int	i;
	char	**checker;

	i = 0;
	checker = ft_split(line, ' ');
	while(checker[0][i])
	{
		i++;
	}
	printf("checker line -> %d\n", i);
	if (i > 1)
	{
		free_map(checker);
		exit_mess("Color must be start with : 'C' or 'F'");
	}
	free_map(checker);
}

void	stock_color(char *line, t_color *color)
{
	char	**tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	printf("line ========== [%s]\n", line);
	checker_line(line);
	if (*line == 'C' || *line == 'F' || *line == '\n')
		line++;
	if (*line == ' ')
		line++;
	tmp = ft_split(line, ',');
	while (tmp[i])
	{	
		printf("str[%d] = %s\n", i, tmp[i]);
		i++;
	}
	if (i != 3)
	{
		free_map(tmp);
		exit_mess("It must be 3 color, no more, no less");
	}
	i = 0;
	while (tmp[i])
	{
		printf("here   %s\n", tmp[i]);
		if (tmp[i][j] == ' ')
			j++;
		if (is_digit(tmp[i]) && tmp[i])
			j++;
		if (!is_digit(tmp[i]))
		{
			printf("nn digit tmp is = [%c]\n", tmp[i][j]);
			free_map(tmp);
			exit_mess("colors must be in a range of 0-255");
		}
		i++;
	}
	color->r = atoi(tmp[0]);
	color->g = atoi(tmp[1]);
	color->b = atoi(tmp[2]);
	printf("color is = %d\n", color->r);
	printf("color is = %d\n", color->g);
	printf("color is = [%d]\n", color->b);
	free_map(tmp);
	check_limits(color);
}

void	parse_color(t_data *data, t_color *color)
{
	int	i = 0;

	while (data->line[i])
	{
		if (data->line[i][0] == 'F')
			stock_color(data->line[i], color);
		else if (data->line[i][0] == 'C')
			stock_color(data->line[i], color);
		i++;
	}
	free_map(data->line);
}