/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 13:30:48 by emercier          #+#    #+#             */
/*   Updated: 2026/06/19 16:56:06 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"
#include "mlx.h"

void	free_game_data(t_game *data)
{
	int	i;

	free_tab(data->map);
	i = 0;
	while (i < __TEXTURES_COUNT)
	{
		if (data->textures[i].ptr)
		{
			mlx_destroy_image(data->textures[i].mlx, data->textures[i].ptr);
			ft_bzero(&data->textures[i], sizeof(*data->textures));
		}
		i++;
	}
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
