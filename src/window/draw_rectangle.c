/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rectangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 20:59:40 by emercier          #+#    #+#             */
/*   Updated: 2026/04/02 21:09:30 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"

void	draw_rectangle(t_image *img, t_rectangle *r)
{
	int		x;
	int		x_end;
	int		y;
	int		y_end;
	t_color	c;

	x = r->pos.x;
	x_end = r->pos.x + r->width;
	if (x_end > img->width)
		x_end = img->width;
	y = r->pos.y;
	y_end = r->pos.y + r->height;
	if (y_end > img->height)
		y_end = img->height;
	c = r->color;
	while (y < y_end)
	{
		x = r->pos.x;
		while (x < x_end)
		{
			put_pixel(img, x, y, c);
			x++;
		}
		y++;
	}
}
