/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunari <nmunari@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:53:11 by nmunari           #+#    #+#             */
/*   Updated: 2025/09/23 15:54:08 by nmunari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static int	len_words(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	int		words;
	char	**new;

	words = count_words(s, c);
	new = ft_calloc(words + 1, sizeof(char *));
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (j < words)
	{
		while (s[i] == c)
			i++;
		new[j] = malloc(sizeof(char) * (len_words(s, c, i) + 1));
		if (!new[j])
			return (NULL);
		k = 0;
		while (s[i] && s[i] != c)
			new[j][k++] = s[i++];
		new[j++][k] = '\0';
	}
	return (new);
}
