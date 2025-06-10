#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_data	data;
	t_color	color;

	parse_file(ac, av);
	init_data(&data, av);
	stock_map(&data);
	stock_line(&data);
	parse_color(&data, &color);
	return (0);
}