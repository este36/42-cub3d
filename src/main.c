/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 19:02:47 by emercier          #+#    #+#             */
/*   Updated: 2026/04/03 15:53:38 by emercier         ###   ########.fr       */
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
	msgbox(MSGBOX_OK, "%s:%d %s\n", __FILE__, __LINE__,
"rm -rf cub3d"
"cc -c -o obj/main.o -Wall -Wextra -Werror -g -Ilibft/ft_printf -Ilibft -Iminilibx-linux -Iinclude src/main.c"
"cc -c -o obj/utils.o -Wall -Wextra -Werror -g -Ilibft/ft_printf -Ilibft -Iminilibx-linux -Iinclude src/utils.c"
"cc -c -o obj/window/create_window.o -Wall -Wextra -Werror -g -Ilibft/ft_printf -Ilibft -Iminilibx-linux -Iinclude src/window/create_window.c"
"cc -c -o obj/window/win_init_hooks.o -Wall -Wextra -Werror -g -Ilibft/ft_printf -Ilibft -Iminilibx-linux -Iinclude src/window/win_init_hooks.c"
"cc -c -o obj/window/show_window.o -Wall -Wextra -Werror -g -Ilibft/ft_printf -Ilibft -Iminilibx-linux -Iinclude src/window/show_window.c"
"cc -c -o obj/window/destroy_window.o -Wall -Wextra -Werror -g -Ilibft/ft_printf -Ilibft -Iminilibx-linux -Iinclude src/window/destroy_window.c"
"cc -c -o obj/window/put_pixel.o -Wall -Wextra -Werror -g -Ilibft/ft_printf -Ilibft -Iminilibx-linux -Iinclude src/window/put_pixel.c"
"cc -c -o obj/window/draw_rectangle.o -Wall -Wextra -Werror -g -Ilibft/ft_printf -Ilibft -Iminilibx-linux -Iinclude src/window/draw_rectangle.c"
"cc -c -o obj/window/draw_text.o -Wall -Wextra -Werror -g -Ilibft/ft_printf -Ilibft -Iminilibx-linux -Iinclude src/window/draw_text.c"
"cc -c -o obj/window/msgbox.o -Wall -Wextra -Werror -g -Ilibft/ft_printf -Ilibft -Iminilibx-linux -Iinclude src/window/msgbox.c"
"cc -o cub3d -Wall -Wextra -Werror -g -Ilibft/ft_printf -Ilibft -Iminilibx-linux -Iinclude obj/main.o obj/utils.o obj/window/create_window.o obj/window/win_init_hooks.o obj/window/show_window.o obj/window/destroy_window.o obj/window/put_pixel.o obj/window/draw_rectangle.o obj/window/draw_text.o obj/window/msgbox.o libft/"
 );
}
