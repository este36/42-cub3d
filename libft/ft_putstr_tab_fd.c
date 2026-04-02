/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_tab_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunari <nmunari@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 18:15:16 by nmunari           #+#    #+#             */
/*   Updated: 2025/12/21 18:19:03 by nmunari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_tab_fd(char **str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putstr_fd(str[i], fd);
		ft_putstr_fd("\n", fd);
		i++;
	}
}
