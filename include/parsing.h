/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 16:18:55 by emercier          #+#    #+#             */
/*   Updated: 2026/04/11 16:20:41 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
#define PARSING_H

#include "cub3d.h"

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
void	free_game_data(t_game *data);
void	print_game_data(t_game *data);

int		init_game(t_game *data, char *filename);


#endif // PARSING_H
