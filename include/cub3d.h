/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunari <nmunari@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 14:00:51 by nmunari           #+#    #+#             */
/*   Updated: 2026/04/07 23:42:06 by nmunari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
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

typedef struct s_game
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	int		floor_color[3];
	int		ceiling_color[3];
	int		map_height;
	int		map_width;
	char	**map;
}	t_game;

int		skip_spaces(char *line);
int		get_element_type(char *line);
int		check_cub(char **cub);
char	**get_cub(char *filename);
int		check_texture(char *path);
int		parse_texture(t_game *data, char *line, t_type type);
int		check_color(char *line);
int		parse_color(t_game *data, char *line, t_type type);

#endif
