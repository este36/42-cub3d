/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunari <nmunari@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 14:00:51 by nmunari           #+#    #+#             */
/*   Updated: 2026/04/07 19:31:19 by nmunari          ###   ########.fr       */
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

typedef struct s_map
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
}	t_map;

int		skip_spaces(char *line);
char	**get_cub(char *filename);
int		check_texture(char *path);

#endif
