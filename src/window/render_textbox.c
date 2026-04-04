/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_textbox.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 23:44:26 by emercier          #+#    #+#             */
/*   Updated: 2026/04/04 15:56:23 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include <stdlib.h>

static void	render_textbox(t_window *w, t_textbox *t)
{
	t_rectangle	rec;
	t_color		bg_color;
	char		buffer[1024];

	bg_color = t->bg_color;
	if (inside_textbox(w->mouse, t))
		bg_color = t->hover_bg_color;
	rec.pos = t->pos;
	rec.width = t->_width;
	rec.height = t->_height;
	fill_rectangle(&w->screen, &rec, bg_color);
	ft_memcpy(buffer, t->content.buf, t->content.len);
	buffer[t->content.len] = 0;
	draw_text(w, t->pos.x + t->padding_x,
		abs((int)t->pos.y + (int)t->padding_y - 1), buffer);
	if (t->border_thickness != 0)
		draw_rectangle(&w->screen, &rec, t->border_thickness, t->border_color);
	if (t->_mem)
		t->_mem->curr = t->_mem->base;
}

void	win_render_textboxes(t_window *w)
{
	size_t	i;

	i = 0;
	while (i < w->_textboxes.len)
	{
		render_textbox(w, ft_darr_get(&w->_textboxes, i));
		i++;
	}
	w->_textboxes.len = 0;
}
