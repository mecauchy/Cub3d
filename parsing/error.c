/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:00:16 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/06/10 14:00:18 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_error(char *message, t_data *data)
{
	if (data)
		free(data);
	ft_printf(RED"\nError\n"GREY"%s\n"RESET, message);
	exit(EXIT_FAILURE);
}

void	exit_mess(char *message)
{
	ft_printf(RED"\nError\n"GREY"%s\n"RESET, message);
	exit(EXIT_FAILURE);
}

void	close_error(int file, char *message, t_data *data)
{
	close(file);
	ft_error(message, data);
}
