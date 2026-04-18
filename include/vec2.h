/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 12:04:21 by emercier          #+#    #+#             */
/*   Updated: 2026/04/18 21:45:49 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC2_H
# define VEC2_H

typedef struct s_vec2
{
	double	x;
	double	y;
}	t_vec2;

t_vec2	vec2_add(t_vec2 a, t_vec2 b);
t_vec2	vec2_mul(t_vec2 a, t_vec2 b);
t_vec2	vec2_sub(t_vec2 a, t_vec2 b);
t_vec2	vec2_scale(t_vec2 a, double scalar);
double	vec2_len(t_vec2 a);
t_vec2	vec2_rot(t_vec2 a, double angle);
t_vec2	vec2_norm(t_vec2 a);
double	vec2_dot(t_vec2 a, t_vec2 b);

typedef struct s_point	t_point;
t_vec2	vec2(double x, double y);
t_point	vec2_to_point(t_vec2 a);
t_vec2	point_to_vec2(t_point a);

// # define V2_FMT "{x=%f, y=%f}"
// # define V2_ARG(v) (v).x, (v).y

#endif // VEC2_H
