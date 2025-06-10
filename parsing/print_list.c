#include "../includes/cub3d.h"

void	print_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		printf("%s\n", data->map[i]);
		i++;
	}
}

void	print_map_line(t_data *data)
{
	int	i;

	i = 0;
	while (data->line[i])
	{
		printf("%s\n", data->line[i]);
		i++;
	}
}