/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_ops_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 12:11:18 by emercier          #+#    #+#             */
/*   Updated: 2026/04/09 12:17:19 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec2.h"

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
