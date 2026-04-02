/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msgbox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 21:10:10 by emercier          #+#    #+#             */
/*   Updated: 2026/04/02 21:58:38 by emercier         ###   ########.fr       */
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
	return (0);
}

int		printed;


int	msgbox(int mode, char *fmt, ...)
{
	t_msgbox	msgbox;
	va_list		arg_list;
	t_dstr		dest;
	t_window	w;
	char		buf[1024];

	msgbox.mode = mode;
	msgbox.text = buf;
	dest.cap = 1024;
	dest.buf = buf;
	va_start(arg_list, fmt);
	ft_printf_fn(write_str, &dest, fmt, &arg_list);
	va_end(arg_list);
	ft_bzero(&w, sizeof(w));
	if (create_window(&w) != 0)
		return (1);
	w.screen.width = 200;
	w.screen.height = 150;
	w.user_data = &msgbox;
	w.main_loop = main_loop;
	if (show_window(&w) != 0)
		return (1);
	destroy_window(&w);
	return (0);
}
