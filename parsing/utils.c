/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:51:00 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/06/19 15:30:03 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_digit(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] < '0' || line[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

// int	is_digit(char *line)
// {
// 	// int	i;
// 	int	nb;

// 	// i = 0;
// 	nb = atoi(line);
// 	if (nb >= 0 && nb <= 255)
// 		return (1);
// 	return (0);
// }

void	check_limits(t_color *color, t_data *data)
{
	if (color->r < 0 || color->r > 255 \
		|| color->g < 0 || color->g > 255 \
		|| color->b < 0 || color->b > 255)
	{
		free_map(data->map);
		free_map(data->line);
		exit_mess("Colors must be on a range 0-255");
	}
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	is_only_space(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
	}
	if (len == i)
		return (1);
	return (0);
}

void	size_all_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		i++;
	}
	data->size_all = i;
}
