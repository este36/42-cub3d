/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 17:24:47 by emercier          #+#    #+#             */
/*   Updated: 2026/04/17 17:49:49 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	_draw(t_game *g, t_rectangle *cell, int x, int y)
{
	if (g->map[y][x] == '0' || ft_isalpha(g->map[y][x]))
	{
		fill_rectangle(&g->win->screen, cell, 0xffffff);
		draw_rectangle(&g->win->screen, cell, 2, 0x181818);
	}
	else if (g->map[y][x] == '1')
	{
		fill_rectangle(&g->win->screen, cell, 0xffcc11);
		draw_rectangle(&g->win->screen, cell, 2, 0x181818);
	}
}

static void	draw_to_screen(t_game *g, t_rectangle *cell, t_point p)
{
	int	y;
	int	x;

	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			cell->pos.x = p.x + x * cell->width;
			cell->pos.y = p.y + y * cell->height;
			_draw(g, cell, x, y);
			x++;
		}
		y++;
	}
}

t_point	render_minimap(t_game *g, t_point p, double scale)
{
	t_rectangle	cell;
	t_point		player_screen;

	ft_bzero(&cell, sizeof(cell));
	cell.width = CELL_WIDTH * scale;
	cell.height = CELL_HEIGHT * scale;
	player_screen = (t_point){
		g->player.pos.x * cell.width + p.x,
		g->player.pos.y * cell.height + p.y
	};
	draw_to_screen(g, &cell, p);
	draw_point(&g->win->screen, player_screen, 10, 0xff0000);
	return (player_screen);
}
