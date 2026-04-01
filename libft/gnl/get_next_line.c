/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunari <nmunari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 17:10:15 by nmunari           #+#    #+#             */
/*   Updated: 2025/12/19 14:19:25 by nmunari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*free_and_null(char **a, char **b)
{
	if (a && *a)
		free(*a);
	if (b && *b)
		free(*b);
	if (a)
		*a = NULL;
	if (b)
		*b = NULL;
	return (NULL);
}

static int	init_line_buffer(char **line, char **buffer)
{
	*buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!*buffer)
		return (0);
	(*buffer)[0] = '\0';
	if (!*line)
	{
		*line = malloc(1);
		if (!*line)
		{
			free(*buffer);
			return (0);
		}
		(*line)[0] = '\0';
	}
	return (1);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*line;
	char		*result;
	ssize_t		n;

	if (fd < 0 || BUFFER_SIZE < 1 || !init_line_buffer(&line, &buffer))
		return (NULL);
	while (!is_next_line(line))
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n == -1)
			return (free_and_null(&line, &buffer));
		if (n == 0)
			break ;
		buffer[n] = '\0';
		line = ft_strjoin_gnl(line, buffer);
	}
	if (!line)
		return (free_and_null(&line, &buffer));
	free(buffer);
	result = extract_line(line);
	buffer = extract_rest(line);
	free(line);
	line = buffer;
	return (result);
}
