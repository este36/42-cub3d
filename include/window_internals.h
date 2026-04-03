/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_internals.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 19:19:50 by emercier          #+#    #+#             */
/*   Updated: 2026/04/03 23:45:52 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_INTERNALS_H
# define WINDOW_INTERNALS_H

# include "window.h"
# include "libft.h"

int		on_win_keyup(int ev, t_window *w);
int		on_win_mousedown(int ev, int x, int y, t_window *w);
int		on_win_mouseup(int ev, int x, int y, t_window *w);
int		on_win_destroy(t_window *w);

int		win_main_loop(t_window *w);

void	win_init_hooks(t_window *w);

void	win_render_textboxes(t_window *w);
void	textbox_calculate_dimensions(t_textbox *t);

void	retrieve_lines(t_darr *lines, t_str_ref *text, size_t max_width);


typedef	struct s_text_query
{
	int		x;
	int		y;
	char	*txt;
}	t_text_query;

#endif // WINDOW_INTERNALS_H
