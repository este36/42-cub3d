/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_init_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 19:44:02 by emercier          #+#    #+#             */
/*   Updated: 2026/04/02 19:52:15 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_internals.h"

int		on_win_keydown(int ev, t_window *w)
{
	w->keys[ev] = true;
	if (w->on_keydown)
		return (w->on_keydown(ev, w));
	return (0);
}

int		on_win_keyup(int ev, t_window *w)
{
	w->keys[ev] = false;
	if (w->on_keyup)
		return (w->on_keyup(ev, w));
	return (0);
}

int		on_win_mousedown(int ev, int x, int y, t_window *w)
{
	if (w->on_mousedown)
		return (w->on_mousedown(ev, x, y, w));
	return (0);
}

int		on_win_mouseup(int ev, int x, int y, t_window *w)
{
	if (w->on_mouseup)
		return (w->on_mouseup(ev, x, y, w));
	return (0);
}

void	win_init_hooks(t_window *w)
{
}
