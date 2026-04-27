/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 12:36:27 by emercier          #+#    #+#             */
/*   Updated: 2026/04/20 12:40:31 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "raycaster.h"
#include <math.h>

t_color	shadow_distance(t_color color, double distance)
{
	const double	shade = fmax(exp(-distance / 20.0), 0.5);
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
		.height = SCREEN_HEIGHT / ray->perp_distance
	};
	if (rec.height > SCREEN_HEIGHT)
		rec.height = SCREEN_HEIGHT;
	rec.pos.y = abs(SCREEN_HEIGHT - rec.height) / 2;
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
	while (i <= SCREEN_WIDTH)
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
