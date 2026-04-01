/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunari <nmunari@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 15:56:22 by nmunari           #+#    #+#             */
/*   Updated: 2025/09/23 16:04:48 by nmunari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(long nb)
{
	if (nb < 10)
		return (1);
	return (1 + int_len(nb / 10));
}

char	*ft_itoa(int n)
{
	long	nb;
	int		sign;
	int		len;
	char	*str;

	nb = n;
	sign = 0;
	if (nb < 0)
	{
		sign = 1;
		nb = -nb;
	}
	len = int_len(nb) + sign;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len > sign)
	{
		str[--len] = (char)((nb % 10) + '0');
		nb /= 10;
	}
	if (sign)
		str[0] = '-';
	return (str);
}
