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
	size_map(&data);
	size_all_map(&data);
	// printf("size all == %d\n", data.size_all);
	check_corner(&data);
	check_end_of_map(&data);
	check_first_line(&data);
	check_last_line(&data);
	return (0);
}