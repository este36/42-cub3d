/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 18:45:25 by emercier          #+#    #+#             */
/*   Updated: 2026/04/28 17:17:58 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTER_H
# define RAYCASTER_H

# include "vec2.h"

typedef struct s_ray
{
	t_vec2	start;
	t_vec2	dir;
	t_vec2	hit;
	double	distance;
	double	perp_distance;
	double	wall_pos;
	bool	tile_found;
	bool	side;
	t_vec2	_unit_step_size;
	t_vec2	_length_1d;
	t_point	_map_check;
	t_point	_step;
}	t_ray;

# define MAX_DISTANCE 10000.0f

t_ray	raycast(char **map, t_vec2 ray_start, t_vec2 ray_dir);

#endif // RAYCASTER_H
