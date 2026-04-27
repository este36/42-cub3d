/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 19:52:02 by emercier          #+#    #+#             */
/*   Updated: 2026/04/16 11:51:37 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"

bool	inside_textbox(t_point p, t_textbox *t)
{
	return (p.x >= t->pos.x && p.y >= t->pos.y
		&& p.x <= t->pos.x + t->_width
		&& p.y <= t->pos.y + t->_height);
}

void	textbox_calculate_dimensions(t_textbox *t)
{
	t->_width = t->padding_x * 2 + t->content.len * CHAR_WIDTH;
	t->_height = t->padding_y * 2 + CHAR_HEIGHT;
}

void	add_textbox(t_window *w, t_textbox *t)
{
	textbox_calculate_dimensions(t);
	ft_darr_push(&w->_textboxes, t);
}

static bool	_alloc(t_textbox *t)
{
	static uint8_t	data[4096];
	static t_balloc	mem = {0};
	char			*tmp;

	t->_mem = &mem;
	if (mem.base == 0)
	{
		mem.base = data;
		mem.curr = data;
		mem.capacity = sizeof(data);
	}
	tmp = balloc(&mem, t->content.len);
	if (!tmp)
		return (false);
	ft_memcpy(tmp, t->content.buf, t->content.len);
	t->content.buf = tmp;
	return (true);
}

t_textbox	textbox(t_point pos, char *fmt, ...)
{
	t_textbox	t;
	static char	buffer[512];
	va_list		lst;

	va_start(lst, fmt);
	ft_bzero(&t, sizeof(t));
	ft_bzero(buffer, sizeof(buffer));
	vsnprintf(buffer, sizeof(buffer), fmt, lst);
	va_end(lst);
	t.pos = pos;
	t.content.buf = buffer;
	t.content.len = ft_strlen(buffer);
	if (!_alloc(&t))
		ft_panic("%s:%d: no memory left!\n", __FILE__, __LINE__);
	t.padding_x = 2;
	t.padding_y = 2;
	t.bg_color = 0xffffff;
	t.hover_bg_color = 0xffffff;
	textbox_calculate_dimensions(&t);
	return (t);
}
