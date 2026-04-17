/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 17:55:03 by emercier          #+#    #+#             */
/*   Updated: 2026/04/17 17:55:04 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"

void	draw_point(t_image *img, t_point pos, size_t thickness, t_color color)
{
	t_rectangle	rec;
	int			mid;

	mid = thickness / 2;
	rec.pos = (t_point){pos.x - mid, pos.y - mid};
	rec.width = thickness;
	rec.height = thickness;
	fill_rectangle(img, &rec, color);
}
