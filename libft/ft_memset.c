/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunari <nmunari@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 16:58:49 by nmunari           #+#    #+#             */
/*   Updated: 2025/09/21 21:19:20 by nmunari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int c, size_t n)
{
	unsigned char	*p;

	if (!ptr)
		return (NULL);
	p = (unsigned char *) ptr;
	while (n--)
		*p++ = (unsigned char) c;
	return (ptr);
}
