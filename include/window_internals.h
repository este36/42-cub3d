/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_internals.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 19:19:50 by emercier          #+#    #+#             */
/*   Updated: 2026/04/02 20:30:56 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_INTERNALS_H
# define WINDOW_INTERNALS_H

# include "window.h"

int		on_win_keyup(int ev, t_window *w);
int		on_win_mousedown(int ev, int x, int y, t_window *w);
int		on_win_mouseup(int ev, int x, int y, t_window *w);
int		on_win_destroy(t_window *w);

int		win_main_loop(t_window *w);

void	win_init_hooks(t_window *w);

#endif // WINDOW_INTERNALS_H
