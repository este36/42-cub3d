/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunari <nmunari@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 19:05:05 by nmunari           #+#    #+#             */
/*   Updated: 2026/04/08 20:24:16 by nmunari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	check_player(char **map)
{
	int	row;
	int	col;
	int	count;

	count = 0;
	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (is_player(map[row][col]))
				count++;
			col++;
		}
		row++;
	}
	if (count == 0)
		return (printf("Error\nNo player found in map\n"), 0);
	if (count > 1)
		return (printf("Error\nMultiple players found in map\n"), 0);
	return (1);
}

static t_dir	get_player_dir(char c)
{
	if (c == 'N')
		return (DIR_NORTH);
	if (c == 'S')
		return (DIR_SOUTH);
	if (c == 'E')
		return (DIR_EAST);
	return (DIR_WEST);
}

int	find_player(char **map, t_game *data)
{
	int	row;
	int	col;

	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (is_player(map[row][col]))
			{
				data->player_x = col;
				data->player_y = row;
				data->player_dir = get_player_dir(map[row][col]);
				return (1);
			}
			col++;
		}
		row++;
	}
	return (0);
}
