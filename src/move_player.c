/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 20:19:25 by emercier          #+#    #+#             */
/*   Updated: 2026/04/19 02:32:16 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_player(t_game *g, t_window *w, float step)
{
	t_vec2	move;
	t_vec2	new_pos;

	if (w->k_left)
		g->player.dir = vec2_rot(g->player.dir, -SENSITIVITY * 2.5);
	if (w->k_right)
		g->player.dir = vec2_rot(g->player.dir, SENSITIVITY * 2.5);
	move = (t_vec2){0};
	if (w->keys['w'])
		move = vec2_add(move, vec2_scale(g->player.dir, step));
	if (w->keys['s'])
		move = vec2_add(move, vec2_scale(g->player.dir, -step));
	if (w->keys['a'])
		move = vec2_add(move,
				vec2_scale((t_vec2){g->player.dir.y, -g->player.dir.x}, step));
	if (w->keys['d'])
		move = vec2_add(move,
				vec2_scale((t_vec2){-g->player.dir.y, g->player.dir.x}, step));
	new_pos.x = g->player.pos.x + move.x;
	new_pos.y = g->player.pos.y + move.y;
	if (g->map[(int)g->player.pos.y][(int)new_pos.x] != '1')
		g->player.pos.x = new_pos.x;
	if (g->map[(int)new_pos.y][(int)g->player.pos.x] != '1')
		g->player.pos.y = new_pos.y;
}
