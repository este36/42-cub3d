/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunari <nmunari@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 17:02:33 by nmunari           #+#    #+#             */
/*   Updated: 2026/04/08 22:27:46 by nmunari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	skip_spaces(char *line)
{
	int	i;

	i = 0;
	while (line[i] && ft_isspace(line[i]))
		i++;
	return (i);
}

int	is_map_line(char *line)
{
	int	i;
	int	has_content;

	i = 0;
	has_content = 0;
	while (line[i])
	{
		if (line[i] == '0' || line[i] == '1' || line[i] == 'N'
			||line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
			has_content = 1;
		else if (!ft_isspace(line[i]) && line[i] != '\n')
			return (0);
		i++;
	}
	return (has_content);
}

int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (1);
	while (line[i])
	{
		if (!ft_isspace(line[i]) && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	get_element_type(char *line)
{
	int	i;

	i = skip_spaces(line);
	if (ft_strncmp(&line[i], "NO ", 3) == 0)
		return (NORTH);
	if (ft_strncmp(&line[i], "SO ", 3) == 0)
		return (SOUTH);
	if (ft_strncmp(&line[i], "WE ", 3) == 0)
		return (WEST);
	if (ft_strncmp(&line[i], "EA ", 3) == 0)
		return (EAST);
	if (ft_strncmp(&line[i], "F ", 2) == 0)
		return (FLOOR);
	if (ft_strncmp(&line[i], "C ", 2) == 0)
		return (CEILING);
	return (NONE);
}
