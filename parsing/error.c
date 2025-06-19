/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:00:16 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/06/19 14:50:54 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_error(char *message, t_data *data)
{
	free_map(data->map);
	exit_mess(message);
	exit(EXIT_FAILURE);
}

void	exit_mess(char *message)
{
	ft_printf(RED"\nError\n"GREY"%s\n"RESET, message);
	exit(EXIT_FAILURE);
}

void	close_error(int file, char *message)
{
	close(file);
	exit_mess(message);
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
