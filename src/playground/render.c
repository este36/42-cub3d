/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 17:23:43 by emercier          #+#    #+#             */
/*   Updated: 2026/04/17 23:15:57 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "raycaster.h"

static void	draw_hit(t_game *g,
		t_ray *ray,
		t_rectangle cell,
		t_point minimap_start)
{
	t_line		line;
	t_textbox	t;

	line = (t_line){
		.start = to_screen(g->player.pos, minimap_start, cell),
		.end = to_screen(ray->hit, minimap_start, cell),
	};
	draw_line(&g->win->screen, &line, 4, 0xff00ee);
	t = textbox((t_point){50, 50},
			"hit: "V2_FMT" ",
			V2_ARG(ray->hit));
	add_textbox(g->win, &t);
}

void	render_playground(t_game *g)
{
	static t_point		minimap_start = (t_point){40, 40};
	t_line				line;
	t_vec2				mouse_cell;
	static t_rectangle	cell = {
		.width = CELL_WIDTH * SCALE,
		.height = CELL_HEIGHT * SCALE,
	};
	t_ray				ray;

	clear_background(g->win, 0x181818);
	line = (t_line){render_minimap(g, minimap_start, SCALE), g->win->mouse};
	draw_line(&g->win->screen, &line, 2, 0x00ff00);
	mouse_cell = (t_vec2){
		(double)(g->win->mouse.x - minimap_start.x) / (double)cell.width,
		(double)(g->win->mouse.y - minimap_start.y) / (double)cell.height
	};
	if (g->win->mouse.x >= g->win->screen.width
		|| g->win->mouse.y >= g->win->screen.height)
		return ;
	ray = raycast(g->map, g->player.pos,
			vec2_norm(vec2_sub(mouse_cell, g->player.pos)));
	if (ray.tile_found)
		draw_hit(g, &ray, cell, minimap_start);
}
