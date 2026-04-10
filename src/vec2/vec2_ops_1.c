/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_ops_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 11:51:41 by emercier          #+#    #+#             */
/*   Updated: 2026/04/09 12:10:43 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec2.h"
#include "math.h"

t_vec2	vec2_add(t_vec2 a, t_vec2 b)
{
	return ((t_vec2){a.x + b.x, a.y + b.y});
}

t_vec2	vec2_sub(t_vec2 a, t_vec2 b)
{
	return ((t_vec2){a.x - b.x, a.y - b.y});
}

t_vec2	vec2_scale(t_vec2 a, double scalar)
{
	return ((t_vec2){a.x * scalar, a.y * scalar});
}

double	vec2_len(t_vec2 a)
{
	return (sqrt(a.x * a.x + a.y * a.y));
}

t_vec2	vec2_rot(t_vec2 a, double angle)
{
	return ((t_vec2){
		a.x * cos(angle) - a.y * sin(angle),
		a.x * sin(angle) + a.y * cos(angle)
	});
}
