/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:55:09 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/06/19 14:55:44 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_len(char	*arg)
{
	int	len;
	int	i;

	len = ft_strlen(arg);
	i = 0;
	while (len >= 0 && arg[len] != '.')
		len--;
	if (arg[len] == '.')
	{
		len++;
		while (arg[len])
		{
			len++;
			i++;
		}
	}
	return (i);
}
