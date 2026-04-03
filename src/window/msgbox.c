/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msgbox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 21:10:10 by emercier          #+#    #+#             */
/*   Updated: 2026/04/03 16:00:06 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "libft.h"
#include "ft_printf_ops.h"
#include "utils.h"

# define CHAR_HEIGHT	12
# define CHAR_WIDTH 	6
# define LINE_SIZE		50
# define PADDING		12
# define BTN_HEIGHT 	50

static int	main_loop(t_window *w)
{
	w->should_render = false;
	return (0);
}

int	msgbox(int mode, char *fmt, ...)
{
	t_msgbox	m;
	va_list		arg_list;
	t_dstr		dest;
	t_window	w;

	m.mode = mode;
	dest.buf = ft_calloc(1, 4096);
	if (!dest.buf)
		return (-1);
	dest.cap = 4096;
	dest.len = 0;
	va_start(arg_list, fmt);
	ft_printf_fn(write_str, &dest, fmt, &arg_list);
	va_end(arg_list);

	m.lines = dest.len / LINE_SIZE;
	if (dest.len % LINE_SIZE)
		m.lines++;
	m.text.buf = dest.buf;
	m.text.len = dest.len;

	ft_bzero(&w, sizeof(w));
	w.screen.width = LINE_SIZE * (CHAR_WIDTH) + 2*PADDING;
	w.screen.height = m.lines * CHAR_HEIGHT + 2*PADDING + BTN_HEIGHT;

	if (create_window(&w) != 0)
		return (-1);
	w.user_data = &m;
	w.main_loop = main_loop;

	ft_printf("w=%d, h=%d, lines=%d\n", w.screen.width, w.screen.height, m.lines);

	t_rectangle		rec;
	ft_bzero(&rec, sizeof(rec));
	rec.width = w.screen.width;
	rec.height = w.screen.height;
	rec.color = 0xffffff;
	draw_rectangle(&w.screen, &rec);

	for (size_t i = 0; i < m.lines; ++i)
	{
		char buffer[LINE_SIZE + 1];
		size_t count = LINE_SIZE;
		if (LINE_SIZE * i + LINE_SIZE > dest.len)
			count = ft_strlen(m.text.buf + LINE_SIZE * i);
		ft_memcpy(buffer, m.text.buf + LINE_SIZE * i, count);
		buffer[count] = 0;
		size_t pos_y = PADDING + CHAR_HEIGHT + i * CHAR_HEIGHT;
		ft_printf("count=%d, pos_y=%d\n", count, pos_y);
		draw_text(&w, PADDING, pos_y, buffer);
	}

	if (show_window(&w) != 0)
		return (-1);
	destroy_window(&w);
	return (0);
}
