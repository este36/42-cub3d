/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vignette.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 13:13:58 by emercier          #+#    #+#             */
/*   Updated: 2026/04/19 14:06:51 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

static void	_init_screen(t_game *game, float *max_dist)
{
	game->center_x = SCREEN_WIDTH / 2;
	game->center_y = SCREEN_HEIGHT / 2;
	*max_dist = sqrtf(game->center_x * game->center_x
			+ game->center_y * game->center_y);
}

int	compute_vignette(t_game *game)
{
	t_point			screen;
	t_vec2			delta;
	float			dist;
	float			max_dist;
	float			r;

	_init_screen(game, &max_dist);
	screen = (t_point){0};
	while (screen.y < SCREEN_HEIGHT)
	{
		screen.x = 0;
		while (screen.x < SCREEN_WIDTH)
		{
			delta.x = fabsf((float)screen.x - game->center_x);
			delta.y = fabsf((float)screen.y - game->center_y);
			dist = sqrtf(delta.x * delta.x + delta.y * delta.y);
			r = 1 - (dist / max_dist) * 0.65;
			game->vignette[screen.y * SCREEN_WIDTH + screen.x] = r;
			screen.x++;
		}
		screen.y++;
	}
	return (0);
}

void	draw_vignette(t_game *game)
{
	int		x;
	int		y;
	t_rgb	pixel;
	float	ratio;

	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			ratio = game->vignette[y * SCREEN_WIDTH + x];
			pixel = (t_rgb)get_pixel(&game->win->screen, x, y);
			pixel.r *= ratio;
			pixel.g *= ratio;
			pixel.b *= ratio;
			put_pixel(&game->win->screen, x, y, pixel.val);
			x++;
		}
		y++;
	}
}
