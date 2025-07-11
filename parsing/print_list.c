/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:49:16 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/06/19 14:57:39 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		ft_printf("%s\n", data->map[i]);
		i++;
	}
}

void	print_map_line(t_data *data)
{
	int	i;

	i = 0;
	while (data->line[i])
	{
		ft_printf("%s\n", data->line[i]);
		i++;
	}
}
