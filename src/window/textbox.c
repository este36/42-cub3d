/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 19:52:02 by emercier          #+#    #+#             */
/*   Updated: 2026/04/04 01:09:07 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

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
