/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunari <nmunari@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 21:50:09 by nmunari           #+#    #+#             */
/*   Updated: 2026/04/16 18:42:40 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "cub3d.h"

static int	count_commas(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ',')
			count++;
		i++;
	}
	return (count);
}

static int	is_valid_number(char *str)
{
	int	i;
	int	has_digit;

	i = 0;
	has_digit = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		has_digit = 1;
		i++;
	}
	while (str[i] && str[i] != '\n')
	{
		if (!ft_isspace(str[i]))
			return (0);
		i++;
	}
	return (has_digit);
}

static int	validate_rgb_array(char **rgb)
{
	int	i;
	int	val;

	i = 0;
	while (rgb[i])
	{
		if (!is_valid_number(rgb[i]))
			return (printf("Error\nInvalid characters in RGB\n"), 0);
		val = ft_atoi(rgb[i]);
		if (val < 0 || val > 255)
			return (printf("Error\nRGB values must be 0-255\n"), 0);
		i++;
	}
	if (i != 3)
		return (printf("Error\nMissing RGB value\n"), 0);
	return (1);
}

int	check_color(char *line)
{
	char	**rgb;
	int		i;

	i = skip_spaces(line);
	i += 2;
	if (count_commas(&line[i]) != 2)
		return (printf("Error\nInvalid RGB format (need 2 commas)\n"), 0);
	rgb = ft_split(&line[i], ',');
	if (!rgb)
		return (0);
	if (!validate_rgb_array(rgb))
	{
		free_tab(rgb);
		return (0);
	}
	free_tab(rgb);
	return (1);
}
