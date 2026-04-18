/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 17:23:43 by emercier          #+#    #+#             */
/*   Updated: 2026/04/18 12:17:25 by emercier         ###   ########.fr       */
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

	line = (t_line){
		.start = to_screen(g->player.pos, minimap_start, cell),
		.end = to_screen(ray->hit, minimap_start, cell),
	};
	draw_line(&g->win->screen, &line, 2, 0xff00ee);
}

void	draw_fov_cone(t_game *g, t_point minimap_start, t_rectangle cell)
{
	t_ray	ray;
	t_vec2	dir;
	float	angle;
	int		i;

	i = 0;
	while (i <= g->win->screen.width)
	{
		angle = -g->fov_half + (i * g->fov_step);
		dir = vec2_rot(g->player.dir, angle);
		ray = raycast(g->map, g->player.pos, dir);
		if (ray.tile_found)
			draw_hit(g, &ray, cell, minimap_start);
		i++;
	}
}

void	render_playground(t_game *g)
{
	static t_point		minimap_start = {40, 40};
	static t_rectangle	cell = {
		.width = CELL_WIDTH * SCALE,
		.height = CELL_HEIGHT * SCALE,
	};

	clear_background(g->win, 0x181818);
	render_minimap(g, minimap_start, SCALE);
	draw_fov_cone(g, minimap_start, cell);
}
