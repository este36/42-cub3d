/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 18:35:08 by emercier          #+#    #+#             */
/*   Updated: 2026/04/02 20:06:06 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "mlx.h"
#include <stdlib.h>

int	destroy_window(t_window *w)
{
	if (w->mlx)
	{
		if (w->screen.ptr)
		{
			mlx_destroy_image(w->mlx, w->screen.ptr);
			w->screen.ptr = NULL;
		}
		if (w->ptr)
		{
			mlx_destroy_window(w->mlx, w->ptr);
			w->ptr = NULL;
		}
		mlx_destroy_display(w->mlx);
		free(w->mlx);
		w->mlx = NULL;
	}
	return (0);
}
