/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 19:02:47 by emercier          #+#    #+#             */
/*   Updated: 2026/04/04 15:56:42 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "window.h"

int	render(t_window *w)
{
	t_textbox	t;
	t_point		p;

	clear_background(w, 0x181818);
	if (w->frame == 1)
		ft_printf("it works!\n");
	p.x = 50;
	p.y = 50;
	textbox(&t, p, "FPS: %d", w->fps);
	add_textbox(w, &t);
	p.y += CHAR_HEIGHT * 4 + 2;
	textbox(&t, p, "mouse: {x=%d, y=%d}", w->mouse.x, w->mouse.y);
	add_textbox(w, &t);
	if (w->mouse.x > 200 && w->mouse.y > 200)
		msgbox("gotcha");
	target_fps(60);
	return (w != NULL);
}

int	main(int argc, char **argv)
{
	t_window	w;

	(void)argc;
	(void)argv;
	ft_bzero(&w, sizeof(w));
	w.title = "Game";
	w.main_loop = render;
	create_window(&w);
	show_window(&w);
	destroy_window(&w);
}
