/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 18:45:00 by emercier          #+#    #+#             */
/*   Updated: 2026/04/28 18:44:00 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "raycaster.h"
#include <math.h>

static void	ray_init_dir(t_ray *ray)
{
	if (ray->dir.x < 0)
	{
		ray->_step.x = -1;
		ray->_length_1d.x = (ray->start.x - (float)ray->_map_check.x);
	}
	else
	{
		ray->_step.x = 1;
		ray->_length_1d.x = ((float)(ray->_map_check.x + 1) - ray->start.x);
	}
	if (ray->dir.y < 0)
	{
		ray->_step.y = -1;
		ray->_length_1d.y = (ray->start.y - (float)ray->_map_check.y);
	}
	else
	{
		ray->_step.y = 1;
		ray->_length_1d.y = ((float)(ray->_map_check.y + 1) - ray->start.y);
	}
	ray->_length_1d = vec2_mul(ray->_length_1d, ray->_unit_step_size);
}

static void	ray_walk(t_ray *ray, char **map)
{
	while (!ray->tile_found && ray->distance < MAX_DISTANCE)
	{
		if (ray->_length_1d.x < ray->_length_1d.y)
		{
			ray->_map_check.x += ray->_step.x;
			ray->distance = ray->_length_1d.x;
			ray->_length_1d.x += ray->_unit_step_size.x;
			ray->side = false;
		}
		else
		{
			ray->_map_check.y += ray->_step.y;
			ray->distance = ray->_length_1d.y;
			ray->_length_1d.y += ray->_unit_step_size.y;
			ray->side = true;
		}
		if (ray->_map_check.x < 0 || ray->_map_check.y < 0
			|| !map[ray->_map_check.y])
			break ;
		if (ray->_map_check.x >= (int)ft_strlen(map[ray->_map_check.y]))
			break ;
		if (map[ray->_map_check.y][ray->_map_check.x] == '1')
			ray->tile_found = true;
	}
}

t_ray	raycast(char **map, t_vec2 ray_start, t_vec2 ray_dir)
{
	t_ray	ray;

	ray = (t_ray){0};
	ray.start = ray_start;
	ray.dir = ray_dir;
	ray._unit_step_size = (t_vec2){
		fabs(1.0 / ray_dir.x),
		fabs(1.0 / ray_dir.y)
	};
	ray._map_check = (t_point){ray_start.x, ray_start.y};
	ray_init_dir(&ray);
	ray_walk(&ray, map);
	if (ray.tile_found)
	{
		ray.hit = vec2_add(ray.start, vec2_scale(ray.dir, ray.distance));
		if (!ray.side)
			ray.wall_pos = ray.hit.y - floor(ray.hit.y);
		else
			ray.wall_pos = ray.hit.x - floor(ray.hit.x);
	}
	return (ray);
}
