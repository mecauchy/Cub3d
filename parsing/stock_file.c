/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:00:44 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/06/18 17:07:34 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	stock_read_line(t_data *data, int file)
{
	char	*line;
	char	*tmp;

	while (1)
	{
		line = get_next_line(file);
		if (!line)
			break ;
		tmp = data->stock;
		data->stock = ft_strjoin(tmp, line);
		free(tmp);
		free(line);
		if (!data->stock)
			close_error(file, "Memory allocation failed", data);
	}
}

void	stock_map(t_data *data)
{
	int		file;

	file = open(data->path, O_RDONLY);
	if (file < 0)
		ft_error("The map couldn't be opened", data);
	data->stock = ft_strdup("");
	if (!data->stock)
		close_error(file, "Memory allocation failed", data);
	stock_read_line(data, file);
	data->map = ft_split(data->stock, '\n');
	// data->map_copy = ft_split(data->stock, '\n'); //ligne 47
	free(data->stock);
	data->stock = NULL;
	if (!data->map)
	{
		free_map(data->map);
		close_error(file, "Invalid map format", data);
	}
	close(file);
	print_map(data);
}
