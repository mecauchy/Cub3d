#include "../includes/cub3d.h"

int	get_max_line(t_data *data)
{
	int	i;
	int	len;
	int	max;

	i = 0;
	max = 0;
	while (data->map[i])
	{
		len = ft_strlen(data->map[i]);
		if (len > max)
			max = ft_strlen(data->map[i]);
		i++;
	}
	printf("max line is == %d\n", max);
	return (max);
}

void	egalize_map(t_data *data)
{
	int	len;
	int	i;
	int	max;
	char	*new_line;

	i = 0;
	max = get_max_line(data);
	while (data->map[i])
	{
		while (ft_strncmp(data->map[i], "NO", 2) == 0 \
		|| ft_strncmp(data->map[i], "SO", 2) == 0 \
		|| ft_strncmp(data->map[i], "WE", 2) == 0 \
		|| ft_strncmp(data->map[i], "EA", 2) == 0 \
		|| ft_strncmp(data->map[i], "C", 1) == 0 \
		|| ft_strncmp(data->map[i], "F", 1) == 0)
			i++;
		len = ft_strlen(data->map[i]);
		if (len < max)
		{
			new_line = (char *)malloc(sizeof(char) * (max + 1));
			if (!new_line)
				return ;
			ft_strcpy(new_line, data->map[i]);
			while (len < max)
				new_line[len++] = ' ';
			new_line[len] = '\0';
			free(data->map[i]);
			data->map[i] = new_line;
			printf("%s\n", data->map[i]);
		}
		i++;
	}
}
