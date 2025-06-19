/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color_01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:49:41 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/06/19 11:49:42 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_size_len(t_data *data)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (data->map[i])
	{
		if (ft_strchr(data->map[i], 'F') || ft_strchr(data->map[i], 'C'))
			count++;
		i++;
	}
	return (count);
}

int	word_count(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		i++;
	}
	return (i);
}

void	stock_line(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->line = (char **)malloc(sizeof(char *) * (ft_size_len(data) + 1));
	if (!data->line)
		return (exit_mess("malloc failed"));
	while (data->map[i])
	{
		if (data->map[i][0] == 'F' || data->map[i][0] == 'C')
		{
			data->line[j] = ft_strdup(data->map[i]);
			if (!data->line[j])
				return ;
			j++;
		}
		i++;
	}
	data->line[j] = NULL;
}
