/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 12:21:31 by emercier          #+#    #+#             */
/*   Updated: 2026/04/18 01:07:45 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "image.h"
# include "libft.h"

typedef struct s_window		t_window;
typedef struct s_textbox	t_textbox;
typedef int					(*t_main_loop_cb)(t_window *w);
typedef int					(*t_on_destroy_cb)(t_window *w);
typedef int					(*t_key_hook)(int ev, t_window *w);
typedef int					(*t_mouse_hook)(int ev, t_point mouse,
								t_window *w);
typedef int					(*t_mouse_move_hook)(t_point prev, t_point curr,
								t_window *w);
typedef int					(*t_textbox_hook)(t_window *w, t_textbox *t);

/* bump allocator */
typedef struct s_balloc
{
	uint8_t	*base;
	uint8_t	*curr;
	size_t	capacity;
}	t_balloc;

void		*balloc(t_balloc *b, size_t size);

typedef struct s_window
{
	void				*mlx;
	void				*ptr;
	void				*user_data;
	char				*title;
	bool				should_close;
	bool				should_render;
	bool				ignore_mouse;
	size_t				frame;
	long				last_frame;
	int					fps;
	double				delta_time;
	t_image				screen;
	t_color				font_color;
	t_point				mouse;
	t_balloc			_memchunk;
	t_darr				_text_queries;
	t_darr				_textboxes;
	t_main_loop_cb		main_loop;
	t_on_destroy_cb		on_destroy;
	t_key_hook			on_keydown;
	t_key_hook			on_keyup;
	t_mouse_hook		on_mousedown;
	t_mouse_hook		on_mouseup;
	t_mouse_move_hook	on_mousemove;
	bool				mouse_left;
	bool				mouse_right;
	bool				k_left;
	bool				k_right;
	bool				k_up;
	bool				k_down;
	uint8_t				keys[256];
}	t_window;

int			create_window(t_window *w);
int			show_window(t_window *w);
void		clear_background(t_window *w, t_color color);
void		target_fps(double fps);
int			destroy_window(t_window *w);

# define CHAR_HEIGHT	13
# define CHAR_WIDTH 	6

int			draw_text(t_window *w, int x, int y, const char *text);

typedef struct s_textbox
{
	t_point			pos;
	t_str_ref		content;
	bool			text_center;
	t_color			bg_color;
	t_color			hover_bg_color;
	size_t			border_thickness;
	t_color			border_color;
	size_t			padding_x;
	size_t			padding_y;
	int				_width;
	int				_height;
	t_balloc		*_mem;
}	t_textbox;

void		add_textbox(t_window *w, t_textbox *t);
bool		inside_textbox(t_point p, t_textbox *t);
t_textbox	textbox(t_point p,
				char *fmt, ...) __attribute__((format(printf, 2, 3)));

# define LINE_SIZE		50
# define PADDING		15
# define BTN_HEIGHT 	40

typedef struct s_msgbox
{
	t_str_ref	text;
	long		last_frame;
	t_darr		lines;
	t_textbox	ok;
}	t_msgbox;

int			msgbox(char *fmt, ...) __attribute__((format(printf, 1, 2)));

#endif
