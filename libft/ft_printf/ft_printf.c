/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunari <nmunari@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:07:09 by nmunari           #+#    #+#             */
/*   Updated: 2025/09/30 21:13:10 by nmunari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	arg_print(const char type, va_list ap)
{
	if (type == 'c')
		return (ft_putchar(va_arg(ap, int)));
	if (type == 's')
		return (ft_putstr(va_arg(ap, char *)));
	if (type == 'p')
		return (ft_putptr(va_arg(ap, void *)));
	if (type == 'd' || type == 'i')
		return (ft_putnbr((long) va_arg(ap, int)));
	if (type == 'u')
		return (ft_putnbr((long) va_arg(ap, unsigned int)));
	if (type == 'x')
		return (puthexa(va_arg(ap, unsigned int), 0));
	if (type == 'X')
		return (puthexa(va_arg(ap, unsigned int), 1));
	if (type == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	int		i;
	va_list	ap;

	if (!str)
		return (0);
	i = 0;
	len = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += arg_print(str[++i], ap);
			i++;
		}
		else
			len += ft_putchar(str[i++]);
	}
	va_end(ap);
	return (len);
}
