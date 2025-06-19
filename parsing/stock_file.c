/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:00:44 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/06/19 16:08:19 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	stock_read_line(t_data *data, int file)
{
	char	*line;
	char	*tmp;
	int		count;

	count = 0;
	while (1)
	{
		line = get_next_line(file);
		if (!line)
			break ;
		count = check_correct_line(line, count);
		tmp = data->stock;
		data->stock = ft_strjoin(tmp, line);
		free(tmp);
		free(line);
		if (!data->stock)
			close_error(file, "Memory allocation failed");
	}
}

void	stock_map(t_data *data)
{
	int		file;

	file = open(data->path, O_RDONLY);
	if (file < 0)
		exit_mess("The map couldn't be opened");
	data->stock = ft_strdup("");
	if (!data->stock)
		close_error(file, "Memory allocation failed");
	stock_read_line(data, file);
	data->map = ft_split(data->stock, '\n');
	free(data->stock);
	data->stock = NULL;
	if (!data->map || data->map[0] == NULL)
	{
		free_map(data->map);
		close_error(file, "Invalid map format");
	}
	close(file);
}
 int	 check_correct_line(char *line, int count)
 {
	int	i;

	i = 0;
	if (ft_strncmp(line, "NO", 3) == 0 \
	|| ft_strncmp(line, "SO", 3) == 0 \
	|| ft_strncmp(line, "EA", 3) == 0 \
	|| ft_strncmp(line, "WE", 3) == 0 \
	|| ft_strncmp(line, "F", 2) == 0 \
	|| ft_strncmp(line, "C", 2) == 0)
		return (count++);
	if (count < 6)
		return (exit_mess("Invalid argument in file"), 1);
	return (count);
 }