/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunari <nmunari@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 20:24:47 by nmunari           #+#    #+#             */
/*   Updated: 2026/06/19 13:38:53 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "cub3d.h"
#include "mlx.h"

void	free_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < __TEXTURES_COUNT)
	{
		if (game->textures[i].ptr)
			mlx_destroy_image(game->win->mlx, game->textures[i].ptr);
		i++;
	}
}

int	parse_elements(char **cub, t_game *data)
{
	int		i;
	t_type	type;

	i = 0;
	while (cub[i])
	{
		type = get_element_type(cub[i]);
		if (type == NORTH || type == SOUTH
			|| type == WEST || type == EAST)
		{
			if (!parse_texture(data, cub[i], type))
				return (free_textures(data), 0);
		}
		else if (type == FLOOR || type == CEILING)
		{
			if (!parse_color(data, cub[i], type))
				return (free_textures(data), 0);
		}
		i++;
	}
	return (1);
}
