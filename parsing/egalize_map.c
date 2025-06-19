/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   egalize_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:49:58 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/06/19 14:24:27 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	get_max_line(t_data *data)
{
	int	i;
	int	len;
	int	max;

	i = 0;
	max = 0;
	while (data->map[i])
	{
		len = ft_strlen(data->map[i]);
		if (len > max)
			max = ft_strlen(data->map[i]);
		i++;
	}
	return (max);
}

void	egalize_map(t_data *data)
{
	char	*new_line;
	int		len;
	int		i;
	int		max;

	i = 0;
	max = get_max_line(data);
	len = 0;
	while (data->start + i < data->size_all)
	{
		len = ft_strlen(data->map[data->start + i]);
		if (len < max)
		{
			new_line = (char *)malloc(sizeof(char) * (max + 1));
			if (!new_line)
				return ;
			ft_strcpy(new_line, data->map[data->start + i]);
			while (len < max)
				new_line[len++] = ' ';
			new_line[len] = '\0';
			free(data->map[data->start + i]);
			data->map[data->start + i] = new_line;
		}
		i++;
	}
}

void	check_nb_perso(t_data *data)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	j = 0;
	count = 0;
	while (data->map[data->start + ++i])
	{
		j = 0;
		while (data->map[data->start + i][j])
		{
			if (data->map[data->start + i][j] == 'N' \
				|| data->map[data->start + i][j] == 'S' \
				|| data->map[data->start + i][j] == 'E' \
				|| data->map[data->start + i][j] == 'W')
				count++;
			j++;
		}
	}
	if (count != 1)
	{
		free_map(data->map);
		exit_mess("It must be one player");
	}
}
