/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunari <nmunari@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 17:58:55 by nmunari           #+#    #+#             */
/*   Updated: 2025/09/21 21:19:19 by nmunari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *) dst;
	s = (const unsigned char *) src;
	if (d == s || n == 0)
		return (dst);
	if (d < s)
		return (ft_memcpy(dst, src, n));
	while (n)
	{
		n--;
		d[n] = s[n];
	}
	return (dst);
}
