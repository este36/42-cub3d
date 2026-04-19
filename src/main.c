/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 19:02:47 by emercier          #+#    #+#             */
/*   Updated: 2026/04/19 13:48:31 by emercier         ###   ########.fr       */
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

void	init_window(t_window *window)
{
	window->title = "cub3d";
	window->on_keydown = on_key_down;
	window->on_mousemove = on_mouse_move;
	window->main_loop = render;
}

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
	init_window(&window);
	create_window(&window);
	init_fov(&game);
	if (compute_vignette(&game) != 0)
		return (1);
	show_window(&window);
	destroy_window(&window);
	// free(game.vignette);
	return (0);
}
