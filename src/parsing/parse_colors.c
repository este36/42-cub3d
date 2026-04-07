/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunari <nmunari@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 21:50:16 by nmunari           #+#    #+#             */
/*   Updated: 2026/04/07 23:35:27 by nmunari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static void	fill_rgb_array(int *color_array, char **rgb_tab)
{
	color_array[0] = ft_atoi(rgb_tab[0]);
	color_array[1] = ft_atoi(rgb_tab[1]);
	color_array[2] = ft_atoi(rgb_tab[2]);
}

int	parse_color(t_render_data *data, char *line, t_type type)
{
	char	**rgb_tab;
	int		i;

	if (!check_color(line))
		return (0);
	i = skip_spaces(line);
	i += 2;
	while (line[i] && ft_isspace(line[i]))
		i++;
	rgb_tab = ft_split(&line[i], ',');
	if (!rgb_tab)
		return (printf("Error\nMalloc failed during RGB parsing\n"), 0);
	if (type == FLOOR)
		fill_rgb_array(data->floor_color, rgb_tab);
	else if (type == CEILING)
		fill_rgb_array(data->ceiling_color, rgb_tab);
	free_tab(rgb_tab);
	return (1);
}

static int	validate_test_colors(char **cub)
{
	int		i;
	t_type	type;

	i = 0;
	while (cub[i])
	{
		type = get_element_type(cub[i]);
		if (type == FLOOR || type == CEILING)
		{
			if (!check_color(cub[i]))
				return (0);
		}
		i++;
	}
	return (1);
}

static void	test_map_colors(char *path)
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
	else if (!validate_test_colors(cub)) 
		printf("Result: INVALID (Color error)\n\n");
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
	printf("\n========== START OF COLOR TESTS ==========\n\n");
	while (maps_to_test[i])
	{
		test_map_colors(maps_to_test[i]);
		i++;
	}
	printf("========== END OF COLOR TESTS ==========\n\n");
	return (0);
} 
