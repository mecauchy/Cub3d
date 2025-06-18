/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:00:33 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/06/18 14:28:01 by mcauchy-         ###   ########.fr       */
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
		printf("here\n");
		printf("\n");
	}
	return (i);
}

char	*check_extension(char *arg)
{
	int	len;
	int	i;
	char	*ret;

	i = 0;
	len = ft_strlen(arg);
	printf("strlen = %d\n", len);
	ret = malloc(sizeof(char) * (ft_len(arg) + 1));
	if (!ret)
		exit (1);
	printf("size ret cub = %d\n", ft_len(arg));
	while (len >= 0 && arg[len] != '.')
		len--;
	if (arg[len] == '.')
	{
		len++;
		while (arg[len])
		{
			printf("%c\n", arg[len]);
			ret[i] = arg[len];
			len++;
			i++;
		}
	}
	ret[i] = '\0';
	printf("return = %s\n", ret);
	return (ret);
}

void	parse_file(int ac, char **av, t_data *data)
{
	char	*ret;

	ret = check_extension(av[1]);
	data->path = av[1];
	printf("AVVVVVVVVVVVVV = %s\n", data->path);
	if (ac > 2)
		exit_mess("the command must contain 2 arguments");
		// ft_putstr_fd("the command must contain 2 arguments", 2);
	if (!(ft_strncmp(ret, "cub", 7) == 0))
		exit_mess("it must be a .cub file");
		// ft_error("it must be a .cub file", 2);
	printf("ret == %s\n", ret);
	free(ret);
}

