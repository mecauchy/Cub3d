/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:02:36 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/06/16 16:07:46 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	PARSING MAP

	1/
		4 textures (NO, SO, WE, EA)
		2 couleurs (F et C)
		Et une seule position de joueur (N ou S ou E ou W)

	2/
		Les lignes du haut et du bas ne doivent contenir que des 1 et des espaces
		Les premières et dernières colonnes de chaque ligne ne doivent être que des 1 ou des espaces
		Aucun 0 ou joueur (N/S/E/W) ne doit toucher un espace ou le bord du fichier
*/

void	size_map(t_data *data)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (data->map[i])
	{
		if (ft_strncmp(data->map[i], "NO", 2) == 0 \
			|| ft_strncmp(data->map[i], "SO", 2) == 0 \
			|| ft_strncmp(data->map[i], "WE", 2) == 0 \
			|| ft_strncmp(data->map[i], "EA", 2) == 0 \
			|| ft_strncmp(data->map[i], "C", 1) == 0 \
			|| ft_strncmp(data->map[i], "F", 1) == 0)
			i++;
		else
		{
			i++;
			count++;
		}
	}
	printf("i === %d\n", i);
	printf("count === %d\n", count);
	data->largeur_map = count;
}

void	check_corner(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->largeur_map)
	{
		while (ft_strncmp(data->map[i], "NO", 2) == 0 \
		|| ft_strncmp(data->map[i], "SO", 2) == 0 \
		|| ft_strncmp(data->map[i], "WE", 2) == 0 \
		|| ft_strncmp(data->map[i], "EA", 2) == 0 \
		|| ft_strncmp(data->map[i], "C", 1) == 0 \
		|| ft_strncmp(data->map[i], "F", 1) == 0)
			i++;
		printf("[] %s\n", data->map[i]);
		if (data->map[i][0] != '1' && data->map[i][0] != ' ')
		{
			printf("invalid here : %c\n", data->map[i][0]);
			exit_mess("Invalid Map");
		}
		else
			i++;
	}
	printf("SUCCESS\n");
}

