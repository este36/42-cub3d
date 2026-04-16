/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 19:02:47 by emercier          #+#    #+#             */
/*   Updated: 2026/04/16 12:43:50 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"
#include "window.h"
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

void	render_game(t_game *g)
{
	clear_background(g->win, 0xffcc11);
}

t_point	render_minimap(t_game *g, t_point p, double scale)
{
	t_rectangle		cell;
	t_rectangle		player;

	ft_bzero(&cell, sizeof(cell));
	cell.width = CELL_WIDTH * scale;
	cell.height = CELL_HEIGHT * scale;
	cell.pos = p;
	for (int y = 0; g->map[y]; y++)
	{
		for (int x = 0; g->map[y][x]; x++)
		{
			cell.pos.x = p.x + x * cell.width;
			cell.pos.y = p.y + y * cell.height;
			if (g->map[y][x] == '0' || ft_isalpha(g->map[y][x]))
			{
				fill_rectangle(&g->win->screen, &cell, 0xffffff);
				draw_rectangle(&g->win->screen, &cell, 2, 0x181818);
			}
			else if (g->map[y][x] == '1')
			{
				fill_rectangle(&g->win->screen, &cell, 0xffcc11);
				draw_rectangle(&g->win->screen, &cell, 2, 0x181818);
			}
		}
	}
	ft_bzero(&player, sizeof(player));
	player.pos.y = g->player.pos.y * cell.height + p.y;
	player.pos.x = g->player.pos.x * cell.width + p.x;
	player.width = 10;
	player.height = 10;
	player.pos.y -= 5;
	player.pos.x -= 5;
	fill_rectangle(&g->win->screen, &player, 0xff0000);
	player.pos.y += 5;
	player.pos.x += 5;
	return (player.pos);
}

t_point to_screen(t_vec2 p, t_point origin, t_rectangle cell)
{
    return (t_point){
        origin.x + p.x * cell.width,
        origin.y + p.y * cell.height
    };
}

void	render_playground(t_game *g)
{
	double scale = 2;
	t_point minimap_start = point(40, 40);
	t_rectangle cell = {
		.width = CELL_WIDTH * scale,
		.height = CELL_HEIGHT * scale,
	};
	clear_background(g->win, 0x181818);
	t_point p = render_minimap(g, minimap_start, 2);
	t_line line = {p, g->win->mouse};
	draw_line(&g->win->screen, &line, 2, 0x00ff00);

	t_vec2 mouse = (t_vec2){
	    (double)(g->win->mouse.x - minimap_start.x) / (double)cell.width,
	    (double)(g->win->mouse.y - minimap_start.y) / (double)cell.height
	};

	if (g->win->mouse.x >= g->win->screen.width || g->win->mouse.y >= g->win->screen.height)
		return ;

	t_vec2 ray_start = g->player.pos;
	t_vec2 ray_dir = vec2_norm(vec2_sub(mouse, ray_start));
	t_vec2 ray_unit_step_size = (t_vec2){
		(ray_dir.x == 0) ? 1e30 : fabs(1.0 / ray_dir.x),
		(ray_dir.y == 0) ? 1e30 : fabs(1.0 / ray_dir.y)
	};
	t_point map_check = (t_point){ray_start.x, ray_start.y};
	t_point step = {0};
	t_vec2 ray_length_1d = {0};

	if (ray_dir.x < 0)
	{
		step.x = -1;
		ray_length_1d.x = (ray_start.x - (float)map_check.x) * ray_unit_step_size.x;
	}
	else
	{
		step.x = 1;
		ray_length_1d.x = ((float)(map_check.x + 1) - ray_start.x) * ray_unit_step_size.x;
	}
	if (ray_dir.y < 0)
	{
		step.y = -1;
		ray_length_1d.y = (ray_start.y - (float)map_check.y) * ray_unit_step_size.y;
	}
	else
	{
		step.y = 1;
		ray_length_1d.y = ((float)(map_check.y + 1) - ray_start.y) * ray_unit_step_size.y;
	}

	double	max_distance = 10000.0f;
	double	distance = 0.0f;
	bool	tile_found = false;
	while (!tile_found && distance < max_distance)
	{
		if (ray_length_1d.x < ray_length_1d.y)
		{
			map_check.x += step.x;
			distance = ray_length_1d.x;
			ray_length_1d.x += ray_unit_step_size.x;
		}
		else
		{
			map_check.y += step.y;
			distance = ray_length_1d.y;
			ray_length_1d.y += ray_unit_step_size.y;
		}
		if (map_check.x < 0 || map_check.y < 0 || !g->map[map_check.y])
			break ;
		if (map_check.x >= (int)ft_strlen(g->map[map_check.y]))
			break ;
		if (g->map[map_check.y][map_check.x] == '1')
			tile_found = true;
	}
	if (tile_found)
	{
		t_vec2 intersection = vec2_add(ray_start, vec2_scale(ray_dir, distance));
	   	line = (t_line){
			.start = to_screen(g->player.pos, minimap_start, cell),
			.end = to_screen(intersection, minimap_start, cell),
		};
		draw_line(&g->win->screen, &line, 4, 0xff00ee);
		t_textbox t = textbox((t_point){50, 50},
				"intersection: "V2_FMT" ",
				V2_ARG(intersection)
		);
		add_textbox(g->win, &t);
	}
}

int	render(t_window *w)
{
	t_game	*g;

	g = w->user_data;
	t_vec2 pos = g->player.pos;
	double step = STEP_SPEED * w->delta_time;
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

void	print_usage(char *argv0)
{
	printf("Usage: %s <.cub filepath>\n", argv0);
}

int	main(int argc, char **argv)
{
	t_window	window;
	t_game		game;

	if (argc != 2)
	{
		printf("Error: invalid number of arguments\n");
		print_usage(argv[0]);
		return (1);
	}
	ft_bzero(&game, sizeof(game));
	if (!init_game(&game, argv[1]))
		return (1);
	print_game_data(&game);
	ft_bzero(&window, sizeof(window));
	window.user_data = &game;
	game.win = &window;
	window.title = "cub3d";
	window.on_keydown = on_key_down;
	window.main_loop = render;
	create_window(&window);
	show_window(&window);
	destroy_window(&window);
	return (0);
}
