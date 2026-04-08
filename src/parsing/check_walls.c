/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunari <nmunari@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 19:15:04 by nmunari           #+#    #+#             */
/*   Updated: 2026/04/08 20:24:17 by nmunari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_walkable(char c)
{
	return (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static int	is_valid_neighbor(char **map, int row, int col)
{
	if (row < 0 || !map[row])
		return (0);
	if (col < 0 || col >= (int)ft_strlen(map[row]))
		return (0);
	if (map[row][col] == ' ')
		return (0);
	return (1);
}

static int	check_cell(char **map, int row, int col)
{
	if (!is_valid_neighbor(map, row - 1, col))
		return (0);
	if (!is_valid_neighbor(map, row + 1, col))
		return (0);
	if (!is_valid_neighbor(map, row, col - 1))
		return (0);
	if (!is_valid_neighbor(map, row, col + 1))
		return (0);
	return (1);
}

int	check_walls(char **map)
{
	int	row;
	int	col;

	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (is_walkable(map[row][col]) && !check_cell(map, row, col))
				return (printf("Error\nMap is not closed\n"), 0);
			col++;
		}
		row++;
	}
	return (1);
}
