/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunari <nmunari@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 14:00:51 by nmunari           #+#    #+#             */
/*   Updated: 2026/04/07 21:26:46 by nmunari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "cub3d.h"

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

typedef struct s_render_data
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
}	t_render_data;

int		skip_spaces(char *line);
int		get_element_type(char *line);
char	**get_cub(char *filename);
int		check_cub(char **cub);
int		check_texture(char *path);

#endif
