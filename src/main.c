/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 19:02:47 by emercier          #+#    #+#             */
/*   Updated: 2026/04/18 01:18:11 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"
#include "window.h"
#include "mlx.h"
#include <math.h>

int	on_key_down(int ev, t_window *w)
{
	t_game	*game;

	game = w->user_data;
	if ((char)ev == '1')
		game->mode = MODE_GAME;
	else if ((char)ev == '2')
		game->mode = MODE_PLAYGROUND;
	return (0);
}

int	render(t_window *w)
{
	t_game	*g;
	t_vec2	pos;
	double	step;

	g = w->user_data;
	pos = g->player.pos;
	step = STEP_SPEED * w->delta_time;
	if (w->keys['w'] && g->map[(int)(pos.y - step)][(int)pos.x] != '1')
		g->player.pos.y -= step;
	if (w->keys['s'] && g->map[(int)(pos.y + step)][(int)pos.x] != '1')
		g->player.pos.y += step;
	if (w->keys['d'] && g->map[(int)(pos.y)][(int)(pos.x + step)] != '1')
		g->player.pos.x += step;
	if (w->keys['a'] && g->map[(int)(pos.y)][(int)(pos.x - step)] != '1')
		g->player.pos.x -= step;
	if (g->mode == MODE_GAME)
		render_game(g);
	if (g->mode == MODE_PLAYGROUND)
		render_playground(g);
	target_fps(50);
	return (0);
}

int	on_mouse_move(t_point prev, t_point curr, t_window *w)
{
	t_game	*game;
	double	angle;
	double	mouse_delta;

	game = w->user_data;
	mouse_delta = curr.x - prev.x;
	angle = SENSITIVITY * mouse_delta;
	game->player.dir = vec2_rot(game->player.dir, angle);
	return (0);
}

/*int	on_mouse_move(t_point prev, t_point curr, t_window *w)
{
	t_game	*game;
	double	angle;
	double	delta_x;

	(void)prev;
	game = w->user_data;
	printf("curr.x=%d, curr.y=%d\n", curr.x, curr.y);
	delta_x = curr.x - (game->screen_width / 2);
	printf("game_width=%d, game_height=%d\n",
		game->screen_width, game->screen_height);
	angle = SENSITIVITY * delta_x;
	game->player.dir = vec2_rot(game->player.dir, angle);
	w->mouse = (t_point){game->screen_width / 2, game->screen_height / 2};
	mlx_mouse_move(w->mlx, w->ptr, w->mouse.x, w->mouse.y);
    return (0);
}*/

int	main(int argc, char **argv)
{
	t_window	window;
	t_game		game;

	if (argc != 2)
	{
		printf("Error: expected 1 argument, got %d\n", argc - 1);
		printf("Usage: %s <*.cub path>\n", argv[0]);
		return (1);
	}
	ft_bzero(&game, sizeof(game));
	if (!init_game(&game, argv[1]))
		return (1);
	print_game_data(&game);
	ft_bzero(&window, sizeof(window));
	window.user_data = &game;
	game.win = &window;
	game.player.dir = (t_vec2){0.0, -1.0};
	window.title = "cub3d";
	window.on_keydown = on_key_down;
	window.on_mousemove = on_mouse_move;
	window.main_loop = render;
	create_window(&window);
	show_window(&window);
	destroy_window(&window);
	return (0);
}
