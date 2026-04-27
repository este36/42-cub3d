/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 17:08:02 by emercier          #+#    #+#             */
/*   Updated: 2026/04/20 12:38:11 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "raycaster.h"
#include <math.h>

void	draw_ceiling(t_game *game)
{
	t_rectangle	rec;
	t_rgb		base;
	t_rgb		shade;
	double		ratio;
	int			i;

	rec = (t_rectangle){
		.width = SCREEN_WIDTH,
		.height = 1
	};
	base = (t_rgb){.r = game->ceiling_color[0], .g = game->ceiling_color[1],
		.b = game->ceiling_color[2]};
	i = 0;
	while (i < game->center_y)
	{
		ratio = (double)(SCREEN_HEIGHT - i) / (double)SCREEN_HEIGHT;
		shade = (t_rgb){.r = base.r * ratio, .g = base.g * ratio,
			.b = base.b * ratio};
		rec.pos.y = i;
		fill_rectangle(&game->win->screen,
			&rec, shade.val);
		i++;
	}
}

void	draw_floor(t_game *game)
{
	t_rectangle	rec;
	t_rgb		base;
	t_rgb		shade;
	double		ratio;
	int			i;

	rec = (t_rectangle){
		.width = SCREEN_WIDTH,
		.height = 1
	};
	base = (t_rgb){.r = game->floor_color[0], .g = game->floor_color[1],
		.b = game->floor_color[2]};
	i = SCREEN_HEIGHT;
	while (i > game->center_y)
	{
		ratio = (double)i / (double)SCREEN_HEIGHT;
		shade = (t_rgb){.r = base.r * ratio, .g = base.g * ratio,
			.b = base.b * ratio};
		rec.pos.y = i;
		fill_rectangle(&game->win->screen,
			&rec, shade.val);
		i--;
	}
}

void	render_game(t_game *game)
{
	draw_ceiling(game);
	draw_floor(game);
	draw_scene(game);
	draw_vignette(game);
}
