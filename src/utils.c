/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 00:55:56 by emercier          #+#    #+#             */
/*   Updated: 2026/04/28 19:51:12 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdlib.h>
#include "vec2.h"
#include "image.h"
#include "cub3d.h"
#include <math.h>

long	now_ms(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
		return (-1);
	return (tv.tv_sec * 1000L + tv.tv_usec / 1000L);
}

t_point	to_screen(t_vec2 p, t_point origin, t_rectangle cell)
{
	return ((t_point){
		origin.x + p.x * cell.width,
		origin.y + p.y * cell.height
	});
}

void	init_fov(t_game *game)
{
	const double	fov = M_PI / 3.0;

	game->fov = fov;
	game->fov_half = fov * 0.5f;
	game->fov_step = fov / game->win->screen.width;
}
