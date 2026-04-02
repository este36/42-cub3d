/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_init_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 19:44:02 by emercier          #+#    #+#             */
/*   Updated: 2026/04/03 01:32:08 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_internals.h"
#include "mlx.h"
#include <X11/keysym.h>
#include <X11/X.h>

int		on_win_keydown(int ev, t_window *w)
{
	if (ev < 256)
		w->keys[ev] = true;
	if (ev == XK_Escape)
	{
		w->should_close = true;
		mlx_loop_end(w->mlx);
		return (0);
	}
	if (w->on_keydown)
		return (w->on_keydown(ev, w));
	return (0);
}

int		on_win_keyup(int ev, t_window *w)
{
	if (ev < 256)
		w->keys[ev] = false;
	if (w->on_keyup)
		return (w->on_keyup(ev, w));
	return (0);
}

int		on_win_mousedown(int ev, int x, int y, t_window *w)
{
	t_point	p;

	p.x = x;
	p.y = y;
	if (w->on_mousedown)
		return (w->on_mousedown(ev, p, w));
	return (0);
}

int		on_win_mouseup(int ev, int x, int y, t_window *w)
{
	t_point	p;

	p.x = x;
	p.y = y;
	if (w->on_mouseup)
		return (w->on_mouseup(ev, p, w));
	return (0);
}

void	win_init_hooks(t_window *w)
{
	mlx_hook(w->ptr, KeyPress, KeyPressMask, (void *)on_win_keydown, w);
	mlx_hook(w->ptr,
			ButtonPress, ButtonPressMask, (void *)on_win_mousedown, w);
	mlx_hook(w->ptr, DestroyNotify, NoEventMask, (void *)on_win_destroy, w);
	mlx_loop_hook(w->mlx, (void *)win_main_loop, w);
}
