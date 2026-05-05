/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 12:36:27 by emercier          #+#    #+#             */
/*   Updated: 2026/04/28 20:54:44 by emercier         ###   ########.fr       */
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

static void	draw_texture_splice(t_texture_splice *tex,
		t_window *win, t_ray *ray)
{
	t_point	target_pos;
	t_color	pixel;

	target_pos = (t_point){tex->target_col, tex->target_start};
	while (target_pos.y < tex->target_end)
	{
		tex->pos.y = tex->y;
		pixel = get_pixel(tex->img, tex->pos.x, tex->pos.y);
		pixel = shadow_distance(pixel, ray->perp_distance);
		put_pixel(&win->screen, target_pos.x, target_pos.y, pixel);
		tex->y += tex->step;
		target_pos.y++;
	}
}

static void	draw_hit(t_game *game, t_ray *ray, int screen_x)
{
	t_texture_splice	tex;
	int					wall_height;

	tex = (t_texture_splice){0};
	if (ray->side && ray->dir.y > 0)
		tex.img = &game->textures[TEX_SOUTH];
	else if (ray->side && ray->dir.y <= 0)
		tex.img = &game->textures[TEX_NORTH];
	else if (!ray->side && ray->dir.x > 0)
		tex.img = &game->textures[TEX_EAST];
	else if (!ray->side && ray->dir.x <= 0)
		tex.img = &game->textures[TEX_WEST];
	tex.target_col = screen_x;
	tex.pos.x = ray->wall_pos * tex.img->width;
	wall_height = SCREEN_HEIGHT / ray->perp_distance;
	tex.target_height = wall_height;
	if (tex.target_height > SCREEN_HEIGHT)
		tex.target_height = SCREEN_HEIGHT;
	tex.target_start = (SCREEN_HEIGHT - tex.target_height) / 2;
	tex.target_end = tex.target_start + tex.target_height;
	tex.step = (double)tex.img->height / wall_height;
	if (wall_height > SCREEN_HEIGHT)
		tex.y = ((wall_height - SCREEN_HEIGHT) / 2.0) * tex.step;
	draw_texture_splice(&tex, game->win, ray);
}

void	draw_scene(t_game *game)
{
	t_ray	ray;
	t_vec2	dir;
	double	angle;
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
