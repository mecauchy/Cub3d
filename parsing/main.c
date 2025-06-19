/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:49:26 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/06/19 14:16:10 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_data(t_data *data, t_color *color, char **av)
{
	(void)av;
	data->map = NULL;
	data->line = NULL;
	data->stock = NULL;
	color->r = 0;
	color->g = 0;
	color->b = 0;
}

int	main(int ac, char **av)
{
	t_data	data;
	t_color	color;

	parse_file(ac, av, &data);
	init_data(&data, &color, av);
	stock_map(&data);
	skip_textures(&data);
	check_nb_textures(&data);
	check_nb_perso(&data);
	stock_line(&data);
	parse_color(&data, &color);
	size_map(&data);
	size_all_map(&data);
	check_corner(&data);
	check_end_of_map(&data);
	check_first_line(&data);
	check_last_line(&data);
	get_max_line(&data);
	egalize_map(&data);
	count_char(&data);
	check_map(&data);
	free_map(data.map);
	return (0);
}
