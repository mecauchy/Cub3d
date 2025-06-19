/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:00:33 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/06/19 15:07:47 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*check_extension(char *arg)
{
	char	*ret;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(arg);
	ret = malloc(sizeof(char) * (ft_len(arg) + 1));
	if (!ret)
		exit (1);
	while (len >= 0 && arg[len] != '.')
		len--;
	if (arg[len] == '.')
	{
		len++;
		while (arg[len])
		{
			ret[i] = arg[len];
			len++;
			i++;
		}
	}
	ret[i] = '\0';
	return (ret);
}

void	parse_file(int ac, char **av, t_data *data)
{
	char	*ret;

	if (ac != 2)
		exit_mess("the command must contain 2 arguments");
	ret = check_extension(av[1]);
	data->path = av[1];
	if (!(ft_strncmp(ret, "cub", 7) == 0))
	{
		free(ret);
		exit_mess("it must be a .cub file");
	}
	free(ret);
}

void	check_map_char(t_data *data, int i, int j)
{
	if (data->map[data->start + i][j] != 'N' \
		&& data->map[data->start + i][j] != 'S' \
		&& data->map[data->start + i][j] != 'E' \
		&& data->map[data->start + i][j] != 'W' \
		&& data->map[data->start + i][j] != '1' \
		&& data->map[data->start + i][j] != '0' && \
		data->map[data->start + i][j] != ' ')
		ft_error("Invalid character in map", data);
}

int	count_char(t_data *data)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (data->map[data->start + i])
	{
		j = 0;
		while (data->map[data->start + i][j])
		{
			check_map_char(data, i, j);
			if (data->map[data->start + i][j] == 'N' \
				|| data->map[data->start + i][j] == 'S' \
				|| data->map[data->start + i][j] == 'E' || \
				data->map[data->start + i][j] == 'W')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	check_map(t_data *data)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = count_char(data);
	while (data->map[data->start + i])
	{
		j = 0;
		while (data->map[data->start + i][j])
		{
			if (data->map[data->start + i][j] != '0' \
				&& data->map[data->start + i][j] != ' ' && len != 1 \
				&& data->map[data->start + i][j] != '1')
			{
				free_map(data->map);
				exit_mess("It must be one player\n(N, S, E, W)");
			}
			j++;
		}
		i++;
	}
}
