/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunari <nmunari@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 17:52:19 by nmunari           #+#    #+#             */
/*   Updated: 2026/04/07 23:42:36 by nmunari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_xpm_extension(char *path)
{
	size_t	len;

	len = ft_strlen(path);
	if (len < 4 || ft_strncmp(path + len - 4, ".xpm", 4) != 0)
	{
		printf("Error\nInvalid texture extension\n");
		return (0);
	}
	return (1);
}

static int	check_file_exists(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\nCannot open texture file\n");
		return (0);
	}
	close(fd);
	return (1);
}

int	check_texture(char *path)
{
	if (!check_xpm_extension(path))
		return (0);
	if (!check_file_exists(path))
		return (0);
	return (1);
}
