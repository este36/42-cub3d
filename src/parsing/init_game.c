/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunari <nmunari@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 20:24:47 by nmunari           #+#    #+#             */
/*   Updated: 2026/04/16 18:43:16 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "cub3d.h"

static int	parse_elements(char **cub, t_game *data)
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

void	free_game_data(t_game *data)
{
	free(data->no_path);
	free(data->so_path);
	free(data->we_path);
	free(data->ea_path);
	free_tab(data->map);
}

int	init_game(t_game *data, char *filename)
{
	char	**cub;

	cub = get_cub(filename);
	if (!cub)
		return (0);
	if (!check_cub(cub))
		return (free_tab(cub), 0);
	if (!parse_elements(cub, data))
		return (free_tab(cub), 0);
	if (!parse_map(cub, data))
		return (free_tab(cub), 0);
	free_tab(cub);
	return (1);
}
