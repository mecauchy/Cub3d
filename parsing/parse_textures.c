/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:50:32 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/06/19 15:40:50 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	skip_textures(t_data *data)
{
	int	i;

	i = 0;
	if (!data->map)
		exit_mess("Empty map");
	while (ft_strncmp(data->map[i], "NO", 2) == 0 \
	|| ft_strncmp(data->map[i], "SO", 2) == 0 \
	|| ft_strncmp(data->map[i], "WE", 2) == 0 \
	|| ft_strncmp(data->map[i], "EA", 2) == 0 \
	|| ft_strncmp(data->map[i], "C", 1) == 0 \
	|| ft_strncmp(data->map[i], "F", 1) == 0)
		i++;
	data->start = i;
	printf("data start ==== %d\n", data->start);
}

void	check_nb_textures(t_data *data)
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
			|| ft_strncmp(data->map[i], "EA", 2) == 0)
		{
			count++;
		}
		if (ft_strchr(data->map[i], ',') != 0)
			break ;
		i++;
	}
	if (count != 4)
		ft_error("It must be 4 textures in Map\nNO, SO, EA, WE", data);
}
