/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_ops_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 12:11:18 by emercier          #+#    #+#             */
/*   Updated: 2026/04/16 12:05:15 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec2.h"
#include "image.h"

t_vec2	vec2_mul(t_vec2 a, t_vec2 b)
{
	return ((t_vec2){a.x * a.x, b.x * b.x});
}

double	vec2_dot(t_vec2 a, t_vec2 b)
{
	return (a.x * b.x + a.y * b.y);
}

t_vec2	vec2_norm(t_vec2 a)
{
	const double	len = vec2_len(a);

	if (len == 0)
		return ((t_vec2){0, 0});
	return ((t_vec2){a.x / len, a.y / len});
}

t_point	vec2_to_point(t_vec2 a)
{
	return ((t_point){(int)a.x, (int)a.y});
}

t_vec2	point_to_vec2(t_point a)
{
	return ((t_vec2){(double)a.x, (double)a.y});
}
