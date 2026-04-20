/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 20:19:25 by emercier          #+#    #+#             */
/*   Updated: 2026/04/20 18:42:07 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	get_map(t_game *g, int x, int y)
{
	static int	map_height = 0;
	int			i;

	if (!map_height)
	{
		i = 0;
		while (g->map[i])
			i++;
		map_height = i;
	}
	if (y >= (int)map_height || y < 0)
		return ('1');
	if (x >= (int)ft_strlen(g->map[y]) || x < 0)
		return ('1');
	return (g->map[y][x]);
}

void	update_pos(t_game *g, t_window *w, float step)
{
	t_vec2	move;
	t_vec2	new_pos;

	move = (t_vec2){0};
	if (w->keys['w'] && !w->keys['s'])
		move = vec2_add(move, vec2_scale(g->player.dir, step));
	if (w->keys['s'] && !w->keys['w'])
		move = vec2_add(move, vec2_scale(g->player.dir, -step));
	if (w->keys['a'] && !w->keys['d'])
		move = vec2_add(move,
				vec2_scale((t_vec2){g->player.dir.y, -g->player.dir.x}, step));
	if (w->keys['d'] && !w->keys['a'])
		move = vec2_add(move,
				vec2_scale((t_vec2){-g->player.dir.y, g->player.dir.x}, step));
	new_pos = (t_vec2){g->player.pos.x + move.x, g->player.pos.y + move.y};
	if (get_map(g, (int)new_pos.x, (int)g->player.pos.y) != '1')
		g->player.pos.x = new_pos.x;
	if (get_map(g, (int)g->player.pos.x, (int)new_pos.y) != '1')
		g->player.pos.y = new_pos.y;
}

void	move_player(t_game *g, t_window *w, float step)
{
	if (w->k_left)
		g->player.dir = vec2_rot(g->player.dir, -SENSITIVITY * KEY_SPEED);
	if (w->k_right)
		g->player.dir = vec2_rot(g->player.dir, SENSITIVITY * KEY_SPEED);
	update_pos(g, w, step);
}
