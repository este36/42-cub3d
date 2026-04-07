/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunari <nmunari@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 14:06:49 by nmunari           #+#    #+#             */
/*   Updated: 2026/04/07 17:37:10 by nmunari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static int	check_file_extension(char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 4 || ft_strncmp(filename + len - 4, ".cub", 4) != 0)
	{
		printf("Error\nInvalid file extension\n");
		return (0);
	}
	return (1);
}

static int	get_file_size(char *filename)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\nCannot open file\n");
		return (-1);
	}
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (count == 0)
	{
		printf("Error\nFile is empty\n");
		return (-1);
	}
	return (count);
}

static void	parse_cub(int fd, char **cub)
{
	int	i;

	i = 0;
	cub[i] = get_next_line(fd);
	while (cub[i])
	{
		i++;
		cub[i] = get_next_line(fd);
	}
}

char	**get_cub(char *filename)
{
	int		fd;
	int		lines;
	char	**cub;

	if (!check_file_extension(filename))
		return (NULL);
	lines = get_file_size(filename);
	if (lines < 0)
		return (NULL);
	cub = malloc(sizeof(char *) * (lines + 1));
	if (!cub)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		free(cub);
		return (NULL);
	}
	parse_cub(fd, cub);
	cub[lines] = NULL;
	close(fd);
	return (cub);
}

/* int	main(void)
{
	char	**cub;
	int		i;
	char	*filename;

	filename = "maps/good/cheese_maze.cub";
	cub = get_cub(filename);
	if (!cub)
		return (1);
	i = 0;
	while (cub[i])
	{
		printf("%s", cub[i]);
		i++;
	}
	return (0);
} */
