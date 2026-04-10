/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunari <nmunari@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 14:00:51 by nmunari           #+#    #+#             */
/*   Updated: 2026/04/10 15:26:37 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "vec2.h"
# include <fcntl.h>
# include <stdio.h>

typedef enum e_type
{
	NONE,
	NORTH,
	SOUTH,
	WEST,
	EAST,
	FLOOR,
	CEILING
}	t_type;

typedef enum e_map_state
{
	MAP_START,
	MAP_READING,
	MAP_FINISHED
}	t_map_state;

typedef enum e_dir
{
	DIR_NORTH,
	DIR_SOUTH,
	DIR_EAST,
	DIR_WEST
}	t_dir;

typedef struct s_player
{
	t_dir	start_dir;
	t_vec2	pos;
	t_vec2	dir;
	double	angle;
}	t_player;

typedef struct s_game
{
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
	int			floor_color[3];
	int			ceiling_color[3];
	char		**map;
	t_player	player;
}	t_game;

int		skip_spaces(char *line);
int		get_element_type(char *line);
int		is_map_line(char *line);
int		is_empty_line(char *line);
int		check_cub(char **cub);
char	**get_cub(char *filename);
int		check_texture(char *path);
int		parse_texture(t_game *data, char *line, t_type type);
int		check_color(char *line);
int		parse_color(t_game *data, char *line, t_type type);
int		check_player(char **map);
int		check_walls(char **map);
int		parse_map(char **cub, t_game *data);
int		find_player(char **map, t_game *data);
int		init_game(t_game *data, char *filename);
void	free_game_data(t_game *data);
void	print_game_data(t_game *data);

#endif
