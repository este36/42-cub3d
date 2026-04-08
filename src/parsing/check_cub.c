/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunari <nmunari@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 16:51:03 by nmunari           #+#    #+#             */
/*   Updated: 2026/04/08 18:23:49 by nmunari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	parse_element(char *line, int *flags)
{
	int	type;

	type = get_element_type(line);
	if (type == NONE || flags[type] == 1)
		return (printf("Error\nUnknown or duplicate element\n"), 0);
	flags[type] = 1;
	return (1);
}

static int	process_line(char *line, int *flags, int *map_state)
{
	int	i;

	i = skip_spaces(line);
	if (line[i] == '\0' || line[i] == '\n')
	{
		if (*map_state == MAP_READING)
			*map_state = MAP_FINISHED;
		return (1);
	}
	if (is_map_line(line))
	{
		if (*map_state == MAP_FINISHED)
			return (printf("Error\nEmpty line inside or after map\n"), 0);
		*map_state = MAP_READING;
	}
	else if (*map_state != MAP_START)
		return (printf("Error\nInvalid line in or after map\n"), 0);
	else if (!parse_element(line, flags))
		return (0);
	return (1);
}

int	check_cub(char **cub)
{
	int			i;
	int			flags[7];
	t_map_state	map_state;

	i = -1;
	while (++i < 7)
		flags[i] = 0;
	i = 0;
	map_state = MAP_START;
	while (cub[i])
	{
		if (!process_line(cub[i], flags, &map_state))
			return (0);
		i++;
	}
	i = 0;
	while (++i <= 6)
	{
		if (flags[i] == 0)
			return (printf("Error\nMissing one or more identifiers\n"), 0);
	}
	if (map_state == MAP_START)
		return (printf("Error\nNo map found in file\n"), 0);
	return (1);
}

/* static void	test_map(char *path)
{
	char	**cub;

	printf("--- Testing %s ---\n", path);
	cub = get_cub(path);
	if (!cub)
	{
		printf("Result: INVALID (Cannot open/read file)\n\n");
		return ;
	}
	
	if (check_cub(cub))
		printf("Result: VALID\n\n");
	else
		printf("Result: INVALID\n\n");
	free_tab(cub);
}

int	main(void)
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
} */
