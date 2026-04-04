/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 19:52:02 by emercier          #+#    #+#             */
/*   Updated: 2026/04/04 12:50:42 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include <stdarg.h>
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

void	textbox(t_textbox *t, t_point pos, char *fmt, ...)
{
	static char	buffer[2048];
	va_list		lst;

	t->pos = pos;
	va_start(lst, fmt);
	ft_bzero(t, sizeof(*t));
	ft_bzero(buffer, sizeof(buffer));
	ft_vsnprintf(buffer, sizeof(buffer), fmt, lst);
	va_end(lst);
	t->content.buf = buffer;
	t->content.len = ft_strlen(buffer);
	t->padding_x = 2;
	t->padding_y = 2;
	t->bg_color = 0xffffff;
	textbox_calculate_dimensions(t);
}
