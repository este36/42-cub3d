/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunari <nmunari@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 19:05:05 by nmunari           #+#    #+#             */
/*   Updated: 2026/04/10 15:30:59 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "math.h"

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

static void	init_player(t_player *p, int row, int col, char dir)
{
	ft_bzero(p, sizeof(p));
	p->pos.x = (double)col + 0.5;
	p->pos.y = (double)row + 0.5;
	if (dir == 'W')
		p->angle = M_PI;
	if (dir == 'E')
		p->angle = 0;
	if (dir == 'N')
		p->angle = 3 * M_PI / 2;
	if (dir == 'S')
		p->angle = M_PI / 2;
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
				init_player(&data->player, row, col, map[row][col]);
				return (1);
			}
			col++;
		}
		row++;
	}
	return (0);
}
