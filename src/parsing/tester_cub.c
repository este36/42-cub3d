/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_cub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunari <nmunari@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 22:15:22 by nmunari           #+#    #+#             */
/*   Updated: 2026/04/08 22:45:28 by nmunari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	test_map(char *path)
{
	t_game	data;

	ft_bzero(&data, sizeof(t_game));
	printf("--- Testing %s ---\n", path);
	if (!init_game(&data, path))
		printf("Result: INVALID\n\n");
	else
	{
		printf("Result: VALID\n\n");
		print_game_data(&data);
	}
	free_game_data(&data);
}

/* int	main(void)
{
	char *path = "maps/bad/player_multiple.cub";
	printf("\n========== START OF TEST ==========\n\n");
	test_map(path);
	printf("========== END OF TEST ==========\n\n");
	return (0);
} */

/* int	main(void)
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
