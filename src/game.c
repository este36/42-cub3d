/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 17:08:02 by emercier          #+#    #+#             */
/*   Updated: 2026/04/19 00:52:43 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "raycaster.h"
#include <math.h>

t_color	shadow_distance(t_color color, double distance)
{
	const double	shade = exp(-distance / 20.0);
	const int		r = ((color >> 16) & 0xFF) * shade;
	const int		g = ((color >> 8) & 0xFF) * shade;
	const int		b = (color & 0xFF) * shade;

	return (((r & 0xFF) << 16) | ((g & 0xFF) << 8) | (b & 0xFF));
}

static void	draw_hit(t_game *game, t_ray *ray, int index)
{
	t_rectangle	rec;

	rec = (t_rectangle){
		.pos = {index, 0},
		.width = 1,
		.height = game->win->screen.height / ray->perp_distance
	};
	if (rec.height > game->win->screen.height)
		rec.height = game->win->screen.height;
	rec.pos.y = abs(game->win->screen.height - rec.height) / 2;
	fill_rectangle(&game->win->screen,
		&rec, shadow_distance(0xff0000, ray->distance));
}

void	draw_scene(t_game *game)
{
	t_ray	ray;
	t_vec2	dir;
	float	angle;
	int		i;

	i = 0;
	while (i <= game->win->screen.width)
	{
		angle = -game->fov_half + (i * game->fov_step);
		dir = vec2_rot(game->player.dir, angle);
		ray = raycast(game->map, game->player.pos, dir);
		if (ray.tile_found)
		{
			ray.perp_distance = ray.distance * cos(angle);
			draw_hit(game, &ray, i);
		}
		i++;
	}
}

void	render_game(t_game *game)
{
	t_rectangle	rec;
	t_rgb		color;

	rec = (t_rectangle){
		.width = game->win->screen.width,
		.height = game->win->screen.height / 2,
	};
	color = (t_rgb){.r = game->ceiling_color[0], .g = game->ceiling_color[1],
		.b = game->ceiling_color[2]};
	fill_rectangle(&game->win->screen,
		&rec, color.val);
	color = (t_rgb){.r = game->floor_color[0], .g = game->floor_color[1],
		.b = game->floor_color[2]};
	rec.pos.y = game->win->screen.height / 2;
	fill_rectangle(&game->win->screen,
		&rec, color.val);
	draw_scene(game);
}
