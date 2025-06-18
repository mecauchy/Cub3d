/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:02:36 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/06/18 16:34:45 by mcauchy-         ###   ########.fr       */
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

	3/
		Checker qu'on a bien des les 2 couleurs : F & C pr l'instant KO
*/

void	size_map(t_data *data)
{
	int	i;
	// int	j;
	int	count;

	i = 0;
	// j = 0;
	count = 0;
	while (data->map[i])
	{
		if (ft_strncmp(data->map[i], "NO", 2) == 0 \
			|| ft_strncmp(data->map[i], "SO", 2) == 0 \
			|| ft_strncmp(data->map[i], "WE", 2) == 0 \
			|| ft_strncmp(data->map[i], "EA", 2) == 0 \
			|| ft_strncmp(data->map[i], "C", 1) == 0 \
			|| ft_strncmp(data->map[i], "F", 1) == 0) \
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

void	size_all_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		i++;
	}
	printf("i === %d\n", i);
	data->size_all = i;
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
			exit_mess("Invalid Mapq");
		}
		else
			i++;
	}
	printf("SUCCESS\n");
}

void	check_end_of_map(t_data *data)
{
	int	i;
	int	len;
	
	i = 0;
	len = 0;
	while (ft_strncmp(data->map[i], "NO", 2) == 0 \
	|| ft_strncmp(data->map[i], "SO", 2) == 0 \
	|| ft_strncmp(data->map[i], "WE", 2) == 0 \
	|| ft_strncmp(data->map[i], "EA", 2) == 0 \
	|| ft_strncmp(data->map[i], "C", 1) == 0 \
	|| ft_strncmp(data->map[i], "F", 1) == 0)
		i++;
	while (i < data->largeur_map)
	{
		len = ft_strlen(data->map[i]);
		if (data->map[i][len - 1] != '1' && data->map[i][len - 1] != ' ')
		{
			printf("invalid at the end of line[%d] : %c\n", i, data->map[i][len - 1]);
			exit_mess("Invalid Map");
		}
		else
			i++;
	}
	printf("SUCCESS 02");
}

void	check_first_line(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (ft_strncmp(data->map[i], "NO", 2) == 0 \
	|| ft_strncmp(data->map[i], "SO", 2) == 0 \
	|| ft_strncmp(data->map[i], "WE", 2) == 0 \
	|| ft_strncmp(data->map[i], "EA", 2) == 0 \
	|| ft_strncmp(data->map[i], "C", 1) == 0 \
	|| ft_strncmp(data->map[i], "F", 1) == 0)
		i++;
	while(data->map[i][j])
	{
		if (data->map[i][j] != '1' && data->map[i][j] != ' ' && data->map[i][j] != '\0')
		{
			printf("false at : %s\n", data->map[i]);
			exit_mess("Invalid Map");
		}
		j++;
	}
}

void	free_map(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	check_last_line(t_data *data)
{
	int	i;

	i = 0;
	printf("taille -> %d, %d, str = %s et [%c]\n", data->size_all, i, data->map[19], data->map[19][data->size_all]);
	printf("taille -> %d, %d, str = %s et [%c]\n", data->size_all, i, data->map[data->size_all - 1], data->map[data->size_all - 1][data->size_all]);
	// dprintf(2, "largeur map = %d -> %c\n", data->size_all, data->map[data->size_all][i]);
	while (data->map[data->size_all -1][i])
	{
		if (data->map[data->size_all- 1][i] != '1' && data->map[data->size_all - 1][i] != ' ' && data->map[data->size_all - 1][i] != '\0')
		{
			// dprintf(2, "invalid at the end of line[%d] : %c\n", i, data->map[data->size_all][i]);
			free_map(data->map);
			exit_mess("Invalid Map01");
		}
		// else
		// {
		// }
		i++;
	}
}