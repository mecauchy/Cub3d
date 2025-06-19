/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:50:20 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/06/19 15:33:19 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	char	**checker;
	int		i;

	i = 0;
	checker = ft_split(line, ' ');
	while (checker[0][i])
		i++;
	if (i > 1)
	{
		free_map(checker);
		exit_mess("Color must start with : 'C' or 'F'");
	}
	free_map(checker);
}

void	stock_color(char *line, t_color *color, t_data *data)
{
	char	**tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = ft_split(line, ',');
	while (tmp[i])
		i++;
	if (i != 3)
		return (free_map(tmp), free_map(data->line), free_map(data->map), \
			exit_mess("It must be 3 color, no more, no less"));
	i = -1;
	while (tmp[++i])
	{
		j = 0;
		if (tmp[i][j] == ' ')
			j++;
		if (!is_digit(tmp[i]) && tmp[i])
			continue ;
		if (is_digit(tmp[i]))
			return (free_map(tmp), free_map(data->line), free_map(data->map), exit_mess(EXIT_COLOR));
	}
	return (color->r = atoi(tmp[0]), color->g = atoi(tmp[1]), \
		color->b = atoi(tmp[2]), free_map(tmp), check_limits(color, data));
}

void	parse_color(t_data *data, t_color *color)
{
	int	i;
	int	j;

	i = -1;
	while (data->line[++i])
	{
		j = 1;
		checker_line(data->line[i]);
		if (data->line[i][0] == 'F')
		{
			while (data->line[i][j] == ' ')
				j ++;
			stock_color(&data->line[i][j], color, data);
		}
		else if (data->line[i][0] == 'C')
		{
			while (data->line[i][j] == ' ')
				j ++;
			stock_color(&data->line[i][j], color, data);
		}
	}
	free_map(data->line);
}
