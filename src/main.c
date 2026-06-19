/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 19:02:47 by emercier          #+#    #+#             */
/*   Updated: 2026/06/19 12:55:34 by emercier         ###   ########.fr       */
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
	angle = SENSITIVITY * mouse_delta * w->delta_time * MOUSE_SPEED;
	game->player.dir = vec2_rot(game->player.dir, angle);
	return (0);
}

void	init(t_window *window, t_game *game)
{
	ft_bzero(game, sizeof(*game));
	ft_bzero(window, sizeof(*window));
	game->win = window;
	window->user_data = game;
	window->title = "cub3d";
	window->on_keydown = on_key_down;
	window->on_mousemove = on_mouse_move;
	window->main_loop = render;
	window->mlx = mlx_init();
	if (!window->mlx)
		exit(1);
}

int	main(int argc, char **argv)
{
	t_game			game;
	t_window		window;

	if (argc != 2)
	{
		printf("Error: expected 1 argument, got %d\n", argc - 1);
		printf("Usage: %s <*.cub path>\n", argv[0]);
		return (1);
	}
	init(&window, &game);
	if (!init_game(&game, argv[1]))
		return (1);
	if (create_window(&window) != 0)
		return (1);
	game.player.dir = (t_vec2){cos(game.player.angle), sin(game.player.angle)};
	print_game_data(&game);
	init_fov(&game);
	if (compute_vignette(&game) != 0)
		return (1);
	show_window(&window);
	free_game_data(&game);
	destroy_window(&window);
	return (0);
}
