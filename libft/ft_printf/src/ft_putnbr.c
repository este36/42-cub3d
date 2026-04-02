/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunari <nmunari@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 20:47:38 by nmunari           #+#    #+#             */
/*   Updated: 2025/09/30 21:06:20 by nmunari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

ssize_t	ft_putnbr(long n)
{
	char	buffer[12];
	int		is_neg;
	int		i;

	if (n == 0)
		return (write(1, "0", 1));
	buffer[11] = '\0';
	is_neg = 0;
	i = 10;
	if (n < 0)
	{
		is_neg = 1;
		n = n * -1;
	}
	while (n)
	{
		buffer[i--] = n % 10 + '0';
		n = n / 10;
	}
	if (is_neg)
		buffer[i--] = '-';
	return (write(1, &buffer[i + 1], (10 - i)));
}
