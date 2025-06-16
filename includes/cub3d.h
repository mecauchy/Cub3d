/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:23:04 by vluo              #+#    #+#             */
/*   Updated: 2025/06/16 15:53:57 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line_bonus.h"
// # include "../minilibx-linux/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>

# define CYAN		"\033[1;96m"
# define RESET		"\033[0m"
# define RED		"\033[1;31m"
# define GREY 		"\033[0;90m"

# define PI 3.14159265358979323846
# define DRAD 0.0174533

# define RES_X 960
# define RES_Y 640
# define CELLSIZE 64

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_data
{
	// void		*mlx;
	// void		*win;
	char		**map;
	char		**map_copy;
	// int			floor_col;
	// int			ceiling_col;
	char		**line;
	char		*stock;
	char		*path;
	int			largeur_map;
	t_color		*color;
}	t_data;



void	stock_read_line(t_data *data, int file);
void	stock_map(t_data *data);
void	ft_error(char *message, t_data *data);
void	close_error(int file, char *message, t_data *data);
int		ft_len(char	*arg);
char	*check_extension(char *arg);
void	init_data(t_data *data, char **av);
void	parse_file(int ac, char **av);
void	print_map(t_data *data);
void	print_map_line(t_data *data);
void	exit_mess(char *message);
int		ft_size_len(t_data *data);
int		word_count(char *str);
void	stock_line(t_data *data);
int		is_digit(char *line);
int		check_limits(t_color *color);
void	stock_color(char *line, t_color *color);
void	size_map(t_data *data);
void	parse_color(t_data *data, t_color *color);
void	check_corner(t_data *data);


#endif