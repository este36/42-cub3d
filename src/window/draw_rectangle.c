/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rectangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 20:08:38 by emercier          #+#    #+#             */
/*   Updated: 2026/04/03 20:27:06 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"

void	draw_rectangle(t_image *img, t_rectangle *r,
			size_t thickness, t_color color)
{
	t_line	line;

	line.start = r->pos;
	line.end.x = r->pos.x + r->width;
	line.end.y = r->pos.y;
	draw_line(img, &line, thickness, color);
	line.start = r->pos;
	line.end.x = r->pos.x;
	line.end.y = r->pos.y + r->height;
	draw_line(img, &line, thickness, color);
	line.start.x = r->pos.x;
	line.start.y = r->pos.y + r->height;
	line.end.x = r->pos.x + r->width;
	line.end.y = r->pos.y + r->height;
	draw_line(img, &line, thickness, color);
	line.start.x = r->pos.x + r->width;
	line.start.y = r->pos.y;
	line.end.x = r->pos.x + r->width;
	line.end.y = r->pos.y + r->height;
	draw_line(img, &line, thickness, color);
}
