/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunari <nmunari@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:00:26 by nmunari           #+#    #+#             */
/*   Updated: 2026/01/26 14:10:16 by nmunari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_push_to_tab(char **tab, char *new_str)
{
	char	**new_tab;
	int		len;
	int		i;

	if (!new_str)
		return (tab);
	len = 0;
	if (tab)
		while (tab[len])
			len++;
	new_tab = malloc(sizeof(char *) * (len + 2));
	if (!new_tab)
		return (NULL);
	i = -1;
	while (++i < len)
		new_tab[i] = tab[i];
	new_tab[len] = new_str;
	new_tab[len + 1] = NULL;
	free(tab);
	return (new_tab);
}
