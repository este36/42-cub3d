/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msgbox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 21:10:10 by emercier          #+#    #+#             */
/*   Updated: 2026/04/04 12:48:23 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "window_internals.h"
#include "libft.h"
#include "ft_printf.h"
#include "utils.h"

static int	on_mouseup(int ev, t_point mouse, t_window *w)
{
	t_msgbox	*m;

	m = w->user_data;
	w->mouse.x = mouse.x;
	w->mouse.y = mouse.y;
	(void)ev;
	if (inside_textbox(w->mouse, &m->ok))
		w->should_close = true;
	return (0);
}

static void	draw_msgbox(t_window *w, t_msgbox *m)
{
	t_rectangle	rec;
	char		buffer[LINE_SIZE + 1];
	t_str_ref	*line;
	size_t		pos_y;
	size_t		i;

	ft_bzero(&rec, sizeof(rec));
	rec.width = w->screen.width;
	rec.height = w->screen.height;
	fill_rectangle(&w->screen, &rec, 0xffffff);
	i = 0;
	while (i < m->lines.len)
	{
		line = ft_darr_get(&m->lines, i);
		ft_memcpy(buffer, line->buf, line->len);
		buffer[line->len] = 0;
		pos_y = PADDING + i * (CHAR_HEIGHT + 2);
		draw_text(w, PADDING, pos_y, buffer);
		i++;
	}
}

static int	main_loop(t_window *w)
{
	t_msgbox	*m;
	int			width;

	m = w->user_data;
	draw_msgbox(w, m);
	ft_bzero(&m->ok, sizeof(m->ok));
	m->ok.padding_x = 20;
	m->ok.padding_y = 10;
	width = 2 * CHAR_WIDTH + m->ok.padding_x;
	m->ok.bg_color = 0xdddddd;
	m->ok.content = c_str_ref("OK");
	m->ok.hover_bg_color = 0xadd8e6;
	m->ok.border_thickness = 2;
	m->ok.border_color = 0x181818;
	m->ok.pos.y = PADDING + (m->lines.len + 1) * CHAR_HEIGHT;
	m->ok.pos.x = w->screen.width / 2 - width / 2;
	add_textbox(w, &m->ok);
	return (0);
}

int	run(t_window *w, t_msgbox *m)
{
	w->screen.width = LINE_SIZE * (CHAR_WIDTH) + 2 * PADDING;
	w->screen.height = m->lines.len * CHAR_HEIGHT + 2 * PADDING + BTN_HEIGHT;
	w->title = "Alert";
	w->on_mouseup = on_mouseup;
	w->main_loop = main_loop;
	w->user_data = m;
	if (create_window(w) != 0)
		return (-1);
	if (show_window(w) != 0)
		return (-1);
	destroy_window(w);
	return (0);
}

int	msgbox(char *fmt, ...)
{
	static char	buffer[2048];
	t_msgbox	m;
	va_list		arg_list;
	t_window	w;
	int			ret;

	ft_bzero(buffer, sizeof(buffer));
	va_start(arg_list, fmt);
	ft_vsnprintf(buffer, sizeof(buffer), fmt, arg_list);
	va_end(arg_list);
	ft_bzero(&m, sizeof(m));
	m.text.buf = buffer;
	m.text.len = ft_strlen(buffer);
	retrieve_lines(&m.lines, &m.text, LINE_SIZE);
	ft_bzero(&w, sizeof(w));
	ret = run(&w, &m);
	free(m.lines.arr);
	return (ret);
}
