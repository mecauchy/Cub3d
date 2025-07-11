/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:23:04 by vluo              #+#    #+#             */
/*   Updated: 2025/06/19 15:36:06 by mcauchy-         ###   ########.fr       */
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

# define EXIT_COLOR "colors are not numbers\nor must be in a range of 0-255"

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_data
{
	char		**map;
	char		**line;
	char		*stock;
	char		*path;
	int			largeur_map;
	int			start;
	int			size_all;
	t_color		*color;
}	t_data;

void	stock_read_line(t_data *data, int file);
void	stock_map(t_data *data);
void	close_error(int file, char *message);
int		ft_len(char	*arg);
char	*check_extension(char *arg);
void	init_data(t_data *data, t_color *color, char **av);
void	parse_file(int ac, char **av, t_data *data);
void	print_map(t_data *data);
void	print_map_line(t_data *data);
void	exit_mess(char *message);
int		ft_size_len(t_data *data);
int		word_count(char *str);
void	stock_line(t_data *data);
int		is_digit(char *line);
void	check_limits(t_color *color, t_data *data);
void	stock_color(char *line, t_color *color, t_data *data);
void	size_map(t_data *data);
void	parse_color(t_data *data, t_color *color);
void	check_corner(t_data *data);
void	check_end_of_map(t_data *data);
void	check_last_line(t_data *data);
void	check_first_line(t_data *data);
void	size_all_map(t_data *data);
void	free_map(char **str);
void	check_map(t_data *data);
char	*ft_strcpy(char *dest, char *src);
int		get_max_line(t_data *data);
int		count_char(t_data *data);
void	egalize_map(t_data *data);
void	check_nb_textures(t_data *data);
void	check_nb_perso(t_data *data);
void	skip_textures(t_data *data);
void	check_map_char(t_data *data, int i, int j);
void	ft_error(char *message, t_data *data);

#endif