/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 18:12:23 by emercier          #+#    #+#             */
/*   Updated: 2026/04/03 19:28:03 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"
#include <math.h>
#include <stdlib.h>

static void	draw_thickness(t_image *img, t_line *line, t_point *p)
{
	int		mid;
	int		start_x;
	t_point	it;
	t_point	end;

	mid = line->thickness / 2;
	it.x = p->x - mid;
	it.y = p->y - mid;
	end.x = p->x + mid;
	end.y = p->y + mid;
	start_x = it.x;
	while (it.y < end.y)
	{
		it.x = start_x;
		while (it.x < end.x)
		{
			put_pixel(img, it.x, it.y, line->color);
			it.x += 1;
		}
		it.y += 1;
	}
}

static void	_init(t_line *line, t_line_ctx *ctx)
{
	ctx->delta.x = abs(line->end.x - line->start.x);
	ctx->delta.y = abs(line->end.y - line->start.y);
	ctx->step.x = 1;
	ctx->step.y = 1;
	if (line->end.x < line->start.x)
		ctx->step.x = -1;
	if (line->end.y < line->start.y)
		ctx->step.y = -1;
	if (line->thickness <= 0)
		line->thickness = 1;
}

void	draw_line(t_image *img, t_line *line)
{
	t_line_ctx	ctx;

	_init(line, &ctx);
	ctx.p = line->start;
	ctx.err = ctx.delta.x - ctx.delta.y;
	while (1)
	{
		draw_thickness(img, line, &ctx.p);
		if (ctx.p.x == line->end.x && ctx.p.y == line->end.y)
			break ;
		ctx.err_dbl = ctx.err * 2;
		if (ctx.err_dbl > (0 - ctx.delta.y))
		{
			ctx.err -= ctx.delta.y;
			ctx.p.x += ctx.step.x;
		}
		if (ctx.err_dbl < ctx.delta.x)
		{
			ctx.err += ctx.delta.x;
			ctx.p.y += ctx.step.y;
		}
	}
}
