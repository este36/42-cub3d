/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 18:22:58 by emercier          #+#    #+#             */
/*   Updated: 2026/04/02 19:18:02 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "libft.h"

int	show_window(t_window *w)
{
	if (w->main_loop == NULL)
		ft_panic("%s:%f: "ANSI_RED"main_loop can't be NULL"ANSI_RESET"\n",
			__FILE__, __LINE__);
	return (0);
}
