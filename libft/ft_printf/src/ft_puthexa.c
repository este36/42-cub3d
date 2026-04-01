/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunari <nmunari@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 19:48:09 by nmunari           #+#    #+#             */
/*   Updated: 2025/09/30 20:38:22 by nmunari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

ssize_t	puthexa(unsigned long n, int up_case)
{
	char	buffer[17];
	char	*base;
	int		i;

	if (n == 0)
		return (write(1, "0", 1));
	if (up_case)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	buffer[16] = '\0';
	i = 15;
	while (n)
	{
		buffer[i--] = base[n % 16];
		n = n / 16;
	}
	return (write(1, &buffer[i + 1], (15 - i)));
}
