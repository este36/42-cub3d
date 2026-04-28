/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 13:02:51 by emercier          #+#    #+#             */
/*   Updated: 2026/04/28 21:04:03 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "window_internals.h"
#include "utils.h"
#include "mlx.h"

void	clear_background(t_window *w, t_color color)
{
	t_rectangle	rec;

	ft_bzero(&rec, sizeof(rec));
	rec.width = w->screen.width;
	rec.height = w->screen.height;
	fill_rectangle(&w->screen, &rec, color);
}

void	update_fps(t_window *w)
{
	static size_t	frame_count = 0;
	long			now;
	long			delta;

	frame_count++;
	w->frame++;
	if (frame_count >= 20)
	{
		now = now_ms();
		delta = now - w->last_frame;
		if (delta > 0.0)
			w->fps = (frame_count * 1000.0) / delta;
		w->delta_time = (delta / 1000.0) / frame_count;
		w->last_frame = now;
		frame_count = 0;
	}
}

void	draw_text_queries(t_window *w)
{
	size_t			i;
	t_text_query	*q;

	i = 0;
	while (i < w->_text_queries.len)
	{
		q = ft_darr_get(&w->_text_queries, i);
		mlx_string_put(w->mlx, w->ptr, q->x, q->y, w->font_color, q->txt);
		i++;
	}
	w->_text_queries.len = 0;
	w->_memchunk.curr = w->_memchunk.base;
}

void	target_fps(double fps)
{
	static double	frame_start = 0.0;
	double			target;
	double			now;
	double			frame_time;

	if (frame_start > 0.0)
	{
		target = 1000.0 / fps;
		now = now_ms();
		frame_time = now - frame_start;
		if (frame_time < target)
			sleep_ms(target - frame_time);
		frame_start += target;
	}
	else
	{
		frame_start = now_ms();
	}
}
