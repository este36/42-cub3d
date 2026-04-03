/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_rectangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 20:24:56 by emercier          #+#    #+#             */
/*   Updated: 2026/04/03 20:25:51 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"

void	fill_rectangle(t_image *img, t_rectangle *r, t_color color)
{
	int		x;
	int		x_end;
	int		y;
	int		y_end;

	x = r->pos.x;
	x_end = r->pos.x + r->width;
	if (x_end > img->width)
		x_end = img->width;
	y = r->pos.y;
	y_end = r->pos.y + r->height;
	if (y_end > img->height)
		y_end = img->height;
	while (y < y_end)
	{
		x = r->pos.x;
		while (x < x_end)
		{
			put_pixel(img, x, y, color);
			x++;
		}
		y++;
	}
}
