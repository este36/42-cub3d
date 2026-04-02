/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 12:21:31 by emercier          #+#    #+#             */
/*   Updated: 2026/04/02 18:59:11 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "image.h"

typedef struct s_window		t_window;
typedef int					(*t_main_loop_cb)(t_window *w);
typedef int					(*t_on_destroy_cb)(t_window *w);
typedef int					(*t_key_hook)(int ev, t_window *w);
typedef int					(*t_mouse_hook)(int ev, int x, int y, t_window *w);

typedef struct s_window
{
	void				*mlx;
	void				*ptr;
	void				*user_data;
	struct s_window		*child;
	char				*title;
	int					should_close;
	size_t				frame;
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

typedef struct s_window_context
{
	t_window	*root;
	t_window	*active;
}	t_window_context;

int		create_window(t_window *w);
int		show_window(t_window *w);
int		destroy_window(t_window *w);

#endif
