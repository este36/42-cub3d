/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 17:50:39 by emercier          #+#    #+#             */
/*   Updated: 2026/04/30 15:19:47 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

#include "window_internals.h"
#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>

static int	init_screen(t_window *w)
{
	t_image	*s;

	s = &w->screen;
	s->ptr = mlx_new_image(w->mlx,
			s->width,
			s->height);
	if (!s->ptr)
		return (-1);
	s->data = mlx_get_data_addr(s->ptr, &s->bits_pp,
			&s->line_len, &s->endian);
	s->bytes_pp = s->bits_pp / 8;
	w->screen.mlx = w->mlx;
	if (ft_darr_init(&w->_text_queries, 64, sizeof(t_text_query)) != 0)
		return (-1);
	if (ft_darr_init(&w->_textboxes, 32, sizeof(t_textbox)) != 0)
		return (-1);
	w->_memchunk.base = ft_calloc(1, 1024 * 10);
	w->_memchunk.curr = w->_memchunk.base;
	w->_memchunk.capacity = 1024 * 10;
	return (0);
}

int	create_window(t_window *w)
{
	if (!w->mlx)
	{
		w->mlx = mlx_init();
		if (!w->mlx)
			return (printf("Error: mlx init failed.\n"), -1);
	}
	if (w->screen.width == 0 || w->screen.height == 0)
	{
		w->screen.width = SCREEN_WIDTH;
		w->screen.height = SCREEN_HEIGHT;
	}
	if (!w->title)
		w->title = "Window Title";
	w->ptr = mlx_new_window(w->mlx,
			w->screen.width,
			w->screen.height,
			w->title);
	if (!w->ptr)
	{
		mlx_destroy_display(w->mlx);
		free(w->mlx);
		return (-1);
	}
	return (init_screen(w));
}
