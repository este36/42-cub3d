/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunari <nmunari@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 18:00:44 by nmunari           #+#    #+#             */
/*   Updated: 2026/04/16 18:42:16 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "cub3d.h"

static char	*get_texture_path(char *line)
{
	int		i;
	int		len;

	i = skip_spaces(line);
	i += 3;
	while (line[i] && ft_isspace(line[i]))
		i++;
	len = 0;
	while (line[i + len] && line[i + len] != '\n' && !ft_isspace(line[i + len]))
		len++;
	return (ft_substr(line, i, len));
}

int	parse_texture(t_game *data, char *line, t_type type)
{
	char	*path;

	path = get_texture_path(line);
	if (!path)
		return (printf("Error\nMalloc failed for texture path\n"), 0);
	if (!check_texture(path))
	{
		free(path);
		return (0);
	}
	if (type == NORTH)
		data->no_path = path;
	else if (type == SOUTH)
		data->so_path = path;
	else if (type == WEST)
		data->we_path = path;
	else if (type == EAST)
		data->ea_path = path;
	return (1);
}

/* static int  validate_test_textures(char **cub)
{
	int		i;
	char	*path;
	t_type	type;

	i = 0;
	while (cub[i])
	{
		type = get_element_type(cub[i]);
		if (type >= NORTH && type <= EAST)
		{
			path = get_texture_path(cub[i]);
			if (!path)
				return (0);
			if (!check_texture(path))
			{
				free(path);
				return (0);
			}
			free(path);
		}
		i++;
	}
	return (1);
}

static void test_map(char *path)
{
	char	**cub;

	printf("--- Testing %s ---\n", path);
	cub = get_cub(path);
	if (!cub)
	{
		printf("Result: INVALID (Cannot open/read file)\n\n");
		return ;
	}
	if (!check_cub(cub))
		printf("Result: INVALID (Structure error)\n\n");
	else if (!validate_test_textures(cub))
		printf("Result: INVALID (Texture error)\n\n");
	else
		printf("Result: VALID\n\n");
		
	free_tab(cub);
}

int main(void)
{
	int		i;
	char	*maps_to_test[] = {
		"maps/good/cheese_maze.cub",
		"maps/good/creepy.cub",
		"maps/good/dungeon.cub",
		"maps/good/library.cub",
		"maps/good/matrix.cub",
		"maps/good/sad_face.cub",
		"maps/good/square_map.cub",
		"maps/good/subject_map.cub",
		"maps/good/test_map_hole.cub",
		"maps/good/test_map.cub",
		"maps/good/test_pos_bottom.cub",
		"maps/good/test_pos_left.cub",
		"maps/good/test_pos_right.cub",
		"maps/good/test_pos_top.cub",
		"maps/good/test_textures.cub",
		"maps/good/test_whitespace.cub",
		"maps/good/works.cub",
		"maps/bad/color_invalid_rgb.cub",
		"maps/bad/color_missing_ceiling_rgb.cub",
		"maps/bad/color_missing_floor_rgb.cub",
		"maps/bad/color_missing.cub",
		"maps/bad/color_none.cub",
		"maps/bad/empty.cub",
		"maps/bad/file_letter_end.cub",
		"maps/bad/filetype_missing",
		"maps/bad/filetype_wrong.buc",
		"maps/bad/forbidden.cub",
		"maps/bad/map_first.cub",
		"maps/bad/map_middle.cub",
		"maps/bad/map_missing.cub",
		"maps/bad/map_only.cub",
		"maps/bad/map_too_small.cub",
		"maps/bad/player_multiple.cub",
		"maps/bad/player_none.cub",
		"maps/bad/player_on_edge.cub",
		"maps/bad/textures_dir.cub",
		"maps/bad/textures_duplicates.cub",
		"maps/bad/textures_forbidden.cub",
		"maps/bad/textures_invalid.cub",
		"maps/bad/textures_missing.cub",
		"maps/bad/textures_none.cub",
		"maps/bad/textures_not_xpm.cub",
		"maps/bad/wall_hole_east.cub",
		"maps/bad/wall_hole_north.cub",
		"maps/bad/wall_hole_south.cub",
		"maps/bad/wall_hole_west.cub",
		"maps/bad/wall_none.cub",
		NULL
	};

	i = 0;
	printf("\n========== START OF TESTS ==========\n\n");
	while (maps_to_test[i])
	{
		test_map(maps_to_test[i]);
		i++;
	}
	printf("========== END OF TESTS ==========\n\n");
	return (0);
}  */
