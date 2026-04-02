/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 19:02:47 by emercier          #+#    #+#             */
/*   Updated: 2026/04/02 21:19:06 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "window.h"

int	render(t_window *w)
{
	if (w->frame == 1)
		ft_printf("it works!\n");
	return (w != NULL);
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	msgbox(MSGBOX_OK, "hey");
}
