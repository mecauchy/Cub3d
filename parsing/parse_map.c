/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:02:36 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/06/19 15:38:09 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	size_map(t_data *data)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (data->map[i])
	{
		if (ft_strncmp(data->map[i], "NO", 2) == 0 \
			|| ft_strncmp(data->map[i], "SO", 2) == 0 \
			|| ft_strncmp(data->map[i], "WE", 2) == 0 \
			|| ft_strncmp(data->map[i], "EA", 2) == 0 \
			|| ft_strncmp(data->map[i], "C", 1) == 0 \
			|| ft_strncmp(data->map[i], "F", 1) == 0)
			i++;
		else
		{
			i++;
			count++;
		}
	}
	data->largeur_map = count;
}

void	check_corner(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->largeur_map)
	{
		if (data->map[data->start + i][0] != '1' \
			&& data->map[data->start + i][0] != ' ')
		{
			free_map(data->map);
			exit_mess("Map must be surrounded by walls or spaces");
		}
		else
			i++;
	}
}

void	check_end_of_map(t_data *data)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (data->map[data->start + i])
	{
		len = ft_strlen(data->map[data->start + i]);
		if (data->map[data->start + i][len - 1] != '1' \
			&& data->map[data->start + i][len - 1] != ' ')
		{
			free_map(data->map);
			exit_mess("3Map must be surrounded by walls or spaces");
		}
		i++;
	}
}

void	check_first_line(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[data->start + i][j])
	{
		if (data->map[data->start + i][j] != '1' \
			&& data->map[data->start + i][j] != ' ' \
			&& data->map[data->start + i][j] != '\0')
		{
			free_map(data->map);
			exit_mess("2Map must be surrounded by walls or spaces");
		}
		j++;
	}
}

void	check_last_line(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[data->size_all -1][i])
	{
		if (data->map[data->size_all - 1][i] != '1' \
			&& data->map[data->size_all - 1][i] != ' ' \
			&& data->map[data->size_all - 1][i] != '\0')
		{
			free_map(data->map);
			exit_mess("1Map must be surrounded by walls or spaces");
		}
		i++;
	}
}
