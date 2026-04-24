/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunari <nmunari@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 20:24:47 by nmunari           #+#    #+#             */
/*   Updated: 2026/04/24 13:32:46 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "cub3d.h"

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
				return (0);
		}
		else if (type == FLOOR || type == CEILING)
		{
			if (!parse_color(data, cub[i], type))
				return (0);
		}
		i++;
	}
	return (1);
}
