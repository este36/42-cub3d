/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 18:22:58 by emercier          #+#    #+#             */
/*   Updated: 2026/04/04 14:20:00 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "window_internals.h"
#include "libft.h"
#include "mlx.h"
#include "utils.h"
#include <stdlib.h>

int	on_win_destroy(t_window *w)
{
	if (w->on_destroy)
		w->on_destroy(w);
	mlx_loop_end(w->mlx);
	return (0);
}

int	win_main_loop(t_window *w)
{
	t_point	mouse;

	mlx_mouse_get_pos(w->mlx, w->ptr, &mouse.x, &mouse.y);
	if (w->on_mousemove && w->frame != 0
		&& w->mouse.x != mouse.x && w->mouse.y != mouse.y)
		w->on_mousemove(w->mouse, mouse, w);
	w->mouse = mouse;
	w->main_loop(w);
	if (!w->should_render)
		return (0);
	if (w->should_close)
		return (on_win_destroy(w));
	win_render_textboxes(w);
	mlx_put_image_to_window(w->mlx, w->ptr, w->screen.ptr, 0, 0);
	if (w->_text_queries.len)
		draw_text_queries(w);
	update_fps(w);
	return (0);
}

static int	win_do_nothing(t_window *w)
{
	w->should_render = false;
	return (0);
}

int	show_window(t_window *w)
{
	w->should_render = true;
	if (w->main_loop == NULL)
		w->main_loop = win_do_nothing;
	win_init_hooks(w);
	mlx_loop(w->mlx);
	return (0);
}
