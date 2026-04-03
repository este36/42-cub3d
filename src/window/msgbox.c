/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msgbox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 21:10:10 by emercier          #+#    #+#             */
/*   Updated: 2026/04/03 17:40:01 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "libft.h"
#include "ft_printf_ops.h"
#include "utils.h"

static int	main_loop(t_window *w)
{
	w->should_render = false;
	return (0);
}

static void	find_lines(t_darr *lines, t_str_ref *text)
{
	size_t		pos;
	t_str_ref	line;

	pos = 0;
	ft_darr_init(lines, 32, sizeof(t_str_ref));
	ft_bzero(&line, sizeof(line));
	while (pos < text->len)
	{
		line.buf = text->buf + pos;
		line.len = 0;
		while (pos < text->len
			&& line.len < LINE_SIZE && text->buf[pos] != '\n')
		{
			pos++;
			line.len++;
		}
		ft_darr_push(lines, &line);
		if (pos < text->len)
			pos++;
	}
}

static void	draw_msgbox(t_window *w, t_msgbox *m)
{
	t_rectangle	rec;
	char		buffer[LINE_SIZE + 1];
	t_str_ref	*line;
	size_t		pos_y;
	size_t		i;

	w->user_data = &m;
	w->main_loop = main_loop;
	ft_bzero(&rec, sizeof(rec));
	rec.width = w->screen.width;
	rec.height = w->screen.height;
	rec.color = 0xffffff;
	draw_rectangle(&w->screen, &rec);
	i = 0;
	while (i < m->lines.len)
	{
		line = ft_darr_get(&m->lines, i);
		ft_memcpy(buffer, line->buf, line->len);
		buffer[line->len] = 0;
		pos_y = PADDING + CHAR_HEIGHT + i * CHAR_HEIGHT;
		draw_text(w, PADDING, pos_y, buffer);
		i++;
	}
}

int	run(t_window *w, t_msgbox *m)
{
	w->screen.width = LINE_SIZE * (CHAR_WIDTH) + 2 * PADDING;
	w->screen.height = m->lines.len * CHAR_HEIGHT + 2 * PADDING + BTN_HEIGHT;
	if (create_window(w) != 0)
		return (-1);
	draw_msgbox(w, m);
	if (show_window(w) != 0)
		return (-1);
	destroy_window(w);
	return (0);
}

int	msgbox(char *fmt, ...)
{
	t_msgbox	m;
	va_list		arg_list;
	t_dstr		dest;
	t_window	w;
	int			ret;

	dest.buf = ft_calloc(1, 4096);
	if (!dest.buf)
		return (-1);
	dest.cap = 4096;
	dest.len = 0;
	va_start(arg_list, fmt);
	ft_printf_fn(write_str, &dest, fmt, &arg_list);
	va_end(arg_list);
	m.text.buf = dest.buf;
	m.text.len = dest.len;
	find_lines(&m.lines, &m.text);
	ft_bzero(&w, sizeof(w));
	ret = run(&w, &m);
	free(m.lines.arr);
	free(dest.buf);
	return (ret);
}
