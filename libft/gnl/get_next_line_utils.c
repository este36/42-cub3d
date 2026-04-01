/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunari <nmunari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 17:10:21 by nmunari           #+#    #+#             */
/*   Updated: 2025/12/19 14:18:31 by nmunari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*new;
	size_t	i;
	size_t	j;

	new = malloc(sizeof(char) * (ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		new[i + j] = s2[j];
		j++;
	}
	new[i + j] = '\0';
	free(s1);
	return (new);
}

int	is_next_line(char *s1)
{
	int	i;

	if (!s1)
		return (0);
	i = 0;
	while (s1[i])
	{
		if (s1[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*extract_line(char *s1)
{
	int		i;
	int		len;
	char	*line;

	if (!s1 || !s1[0])
		return (NULL);
	i = 0;
	if (is_next_line(s1))
	{
		while (s1[i] != '\n')
			i++;
		len = i + 1;
	}
	else
		len = ft_strlen_gnl(s1);
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	i = -1;
	while (++i < len)
		line[i] = s1[i];
	line[len] = '\0';
	return (line);
}

char	*extract_rest(char *s1)
{
	int		i;
	int		j;
	char	*line;

	if (!s1 || !s1[0])
		return (NULL);
	i = 0;
	while (s1[i] && s1[i] != '\n')
		i++;
	if (!s1[i])
		return (NULL);
	j = i;
	while (s1[i] != '\0')
		i++;
	line = malloc(sizeof(char) * (i - j));
	if (!line)
		return (NULL);
	i = j + 1;
	j = 0;
	while (s1[i] != '\0')
		line[j++] = s1[i++];
	line[j] = '\0';
	return (line);
}
