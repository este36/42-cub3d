/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 12:21:31 by emercier          #+#    #+#             */
/*   Updated: 2026/04/02 17:12:39 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

typedef struct s_window		t_window;
typedef int					(*t_main_loop_cb)(t_window *w);
typedef int					(*t_on_destroy_cb)(t_window *w);
typedef int					(*t_key_hook)(int ev, t_window *w);
typedef int					(*t_mouse_hook)(int ev, int x, int y, t_window *w);

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_image
{
	void	*ptr;
	char	*data;
	int		width;
	int		height;
	int		endian;
	int		bits_pp;
	int		bytes_pp;
	int		line_len;
}	t_image;

typedef struct s_window
{
	void				*mlx;
	void				*win;
	void				*user_data;
	struct s_window		*child;
	const char			*title;
	int					should_close;
	t_image				screen;
	t_main_loop_cb		main_loop;
	t_on_destroy_cb		on_destroy;
	t_key_hook			on_keydown;
	t_key_hook			on_keyup;
	t_mouse_hook		on_mousedown;
	t_mouse_hook		on_mouseup;
	t_mouse_hook		on_mousemove;
	uint8_t				keys[256];
}	t_window;

int		create_window(t_window *w);
void	put_pixel(t_image *i, int x, int y, int color);

typedef struct s_rectangle
{
	t_point	pos;
	int		width;
	int		height;
	int		color;
}	t_rectangle;

typedef struct s_line
{
	t_point start;
	t_point	end;
	int		thickness;
	int		color;
}	t_line;

void	draw_rectangle(t_image *i, t_rectangle *rectangle);
void	draw_line(t_image *i, t_line *line);

#endif
