/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunari <nmunari@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 17:19:04 by nmunari           #+#    #+#             */
/*   Updated: 2026/04/08 18:58:41 by nmunari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	find_map_start(char **cub)
{
	int	i;

	i = 0;
	while (cub[i] && !is_map_line(cub[i]))
		i++;
	return (i);
}

static int	count_map_lines(char **cub, int start)
{
	int	i;

	i = start;
	while (cub[i] && is_map_line(cub[i]))
		i++;
	return (i - start);
}

static char	**extract_map(char **cub)
{
	int		start;
	int		height;
	char	**map;
	int		i;

	start = find_map_start(cub);
	if (!cub[start])
		return (NULL);
	height = count_map_lines(cub, start);
	map = ft_calloc(height + 1, sizeof(char *));
	if (!map)
		return (NULL);
	i = 0;
	while (i < height)
	{
		map[i] = ft_strtrim(cub[start + i], "\n");
		if (!map[i])
			return (free_tab(map), NULL);
		i++;
	}
	return (map);
}

/* int	main(void)
{
	char	**cub;
	char	**map;
	int		i;

	cub = get_cub("maps/good/cheese_maze.cub");
	if (!cub)
		return (1);
	map = extract_map(cub);
	if (!map)
	{
		free_tab(cub);
		return (printf("extract_map failed\n"), 1);
	}
	i = 0;
	while (map[i])
	{
		printf("[%d] \"%s\"\n", i, map[i]);
		i++;
	}
	printf("height: %d\n", i);
	free_tab(map);
	free_tab(cub);
	return (0);
} */
