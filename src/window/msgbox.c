/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msgbox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 21:10:10 by emercier          #+#    #+#             */
/*   Updated: 2026/04/03 00:26:30 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "libft.h"
#include "ft_printf_ops.h"

static int	main_loop(t_window *w)
{
	const t_msgbox	*msgbox = w->user_data;
	t_rectangle	rec;

	ft_bzero(&rec, sizeof(rec));
	rec.width = w->screen.width;
	rec.height = w->screen.height;
	rec.color = 0xffffff;
	draw_rectangle(&w->screen, &rec);
	draw_text(w, w->screen.width * 0.1, w->screen.height * 0.1, msgbox->text);
	w->should_render = false;
	return (0);
}

int	msgbox(int mode, char *fmt, ...)
{
	t_msgbox	msgbox;
	va_list		arg_list;
	t_dstr		dest;
	t_window	w;

	msgbox.mode = mode;
	dest.buf = ft_calloc(1, 1024);
	if (!dest.buf)
		return (-1);
	dest.cap = 1024;
	dest.len = 0;
	va_start(arg_list, fmt);
	ft_printf_fn(write_str, &dest, fmt, &arg_list);
	va_end(arg_list);
	msgbox.text = dest.buf;
	ft_bzero(&w, sizeof(w));
	w.screen.width = 200 * 1.5;
	w.screen.height = 150 * 1.5;
	if (create_window(&w) != 0)
		return (-1);
	w.user_data = &msgbox;
	w.main_loop = main_loop;
	if (show_window(&w) != 0)
		return (-1);
	destroy_window(&w);
	return (0);
}
