/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 20:02:46 by emercier          #+#    #+#             */
/*   Updated: 2026/04/04 00:14:29 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "window_internals.h"
#include "mlx.h"
#include <stdio.h>

void	retrieve_lines(t_darr *lines, t_str_ref *text, size_t max_width)
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
			&& line.len < max_width && text->buf[pos] != '\n')
		{
			pos++;
			line.len++;
		}
		ft_darr_push(lines, &line);
		if (pos < text->len)
			pos++;
	}
}

void	*balloc(t_balloc *b, size_t size)
{
	void	*result;
	size_t	len;

	len = b->curr - b->base;
	if (len + size > b->capacity)
		return (NULL);
	result = b->curr;
	b->curr += size;
	return (result);
}

int	draw_text(t_window *w, int x, int y, const char *text)
{
	const size_t	len = ft_strlen(text);
	char			*buf;
	t_text_query	q;

	buf = balloc(&w->_memchunk, len + 1);
	if (!buf)
		ft_panic("%s:%d: memory capacity exceeded!\n", __FILE__, __LINE__);
	ft_memcpy(buf, text, len);
	buf[len] = '\0';
	q.txt = buf;
	q.x = x;
	q.y = y + CHAR_HEIGHT;
	ft_darr_push(&w->_text_queries, &q);
	return (0);
}
