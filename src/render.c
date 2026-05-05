/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 12:38:03 by emercier          #+#    #+#             */
/*   Updated: 2026/04/28 20:46:02 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render(t_window *w)
{
	t_game	*g;

	g = w->user_data;
	move_player(g, w);
	if (g->mode == MODE_GAME)
		render_game(g);
	if (g->mode == MODE_PLAYGROUND)
		render_playground(g);
	target_fps(120);
	return (0);
}
