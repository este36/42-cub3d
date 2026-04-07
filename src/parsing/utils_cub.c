/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunari <nmunari@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 17:02:33 by nmunari           #+#    #+#             */
/*   Updated: 2026/04/07 21:26:40 by nmunari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	skip_spaces(char *line)
{
	int	i;

	i = 0;
	while (line[i] && ft_isspace(line[i]))
		i++;
	return (i);
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
