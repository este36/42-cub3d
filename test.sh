test() {
	file=$1
	valgrind -s '--leak-check=full' ./cub3D $file
}

echo ""
echo "/////////"
echo ""
echo "BAD MAPS"
echo ""
echo "/////////"
echo ""

test maps/bad/color_invalid_rgb.cub
test maps/bad/color_missing.cub
test maps/bad/color_missing_ceiling_rgb.cub
test maps/bad/color_missing_floor_rgb.cub
test maps/bad/color_none.cub
test maps/bad/empty.cub
test maps/bad/file_letter_end.cub
test maps/bad/filetype_missing
test maps/bad/filetype_wrong.buc
test maps/bad/forbidden.cub
test maps/bad/map_first.cub
test maps/bad/map_middle.cub
test maps/bad/map_missing.cub
test maps/bad/map_only.cub
test maps/bad/map_too_small.cub
test maps/bad/player_multiple.cub
test maps/bad/player_none.cub
test maps/bad/player_on_edge.cub
test maps/bad/textures_dir.cub
test maps/bad/textures_duplicates.cub
test maps/bad/textures_forbidden.cub
test maps/bad/textures_invalid.cub
test maps/bad/textures_missing.cub
test maps/bad/textures_none.cub
test maps/bad/textures_not_xpm.cub
test maps/bad/wall_hole_east.cub
test maps/bad/wall_hole_north.cub
test maps/bad/wall_hole_south.cub
test maps/bad/wall_hole_west.cub
test maps/bad/wall_none.cub

echo ""
echo "/////////"
echo ""
echo "GOOD MAPS"
echo ""
echo "/////////"
echo ""

test maps/good/cheese_maze.cub
test maps/good/creepy.cub
test maps/good/dungeon.cub
test maps/good/library.cub
test maps/good/matrix.cub
test maps/good/sad_face.cub
test maps/good/square_map.cub
test maps/good/subject_map.cub
test maps/good/test_map.cub
test maps/good/test_map_hole.cub
test maps/good/test_pos_bottom.cub
test maps/good/test_pos_left.cub
test maps/good/test_pos_right.cub
test maps/good/test_pos_top.cub
test maps/good/test_textures.cub
test maps/good/test_whitespace.cub
test maps/good/works.cub
