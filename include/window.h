/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 12:21:31 by emercier          #+#    #+#             */
/*   Updated: 2026/04/03 01:06:29 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "image.h"
# include "libft.h"

typedef struct s_window		t_window;
typedef int					(*t_main_loop_cb)(t_window *w);
typedef int					(*t_on_destroy_cb)(t_window *w);
typedef int					(*t_key_hook)(int ev, t_window *w);
typedef int					(*t_mouse_hook)(int ev, t_point mouse,
								t_window *w);
typedef int					(*t_mouse_move_hook)(t_point prev, t_point curr,
								t_window *w);

/* bump allocator */
typedef struct s_balloc
{
	uint8_t	*base;
	uint8_t	*curr;
	size_t	capacity;
}	t_balloc;

typedef struct s_window
{
	void				*mlx;
	void				*ptr;
	void				*user_data;
	char				*title;
	int					should_close;
	int					should_render;
	size_t				frame;
	t_image				screen;
	t_color				font_color;
	t_point				mouse;
	t_balloc			_memchunk;
	t_darr				_text_queries;
	t_main_loop_cb		main_loop;
	t_on_destroy_cb		on_destroy;
	t_key_hook			on_keydown;
	t_key_hook			on_keyup;
	t_mouse_hook		on_mousedown;
	t_mouse_hook		on_mouseup;
	t_mouse_move_hook	on_mousemove;
	uint8_t				keys[256];
}	t_window;

int		create_window(t_window *w);
int		show_window(t_window *w);
int		destroy_window(t_window *w);

int		draw_text(t_window *w, int x, int y, const char *text);

typedef struct s_msgbox
{
	char	*text;
	long	last_frame;
	int		mode;
}	t_msgbox;

# define MSGBOX_OK 0
# define MSGBOX_YESNO 1

/*
 * if mode == MSGBOX_OK:
 * 	return value is either -1 on error or 0 on sucess.
 * if mode == MSGBOX_YESNO:
 *  return value is either -1 on error or 0 if the user clicked on NO
 *  or escape button and 1 if the user clicked on OK
 */
int		msgbox(int mode, char *fmt, ...) __attribute__((format(printf, 2, 3)));

#endif
