/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 12:17:00 by emercier          #+#    #+#             */
/*   Updated: 2026/04/04 12:43:11 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_spec.h"

int	ft_vdsprintf(t_dstr *dstr, const char *fmt, va_list lst)
{
	int		ret;
	va_list	tmp;

	va_copy(tmp, lst);
	ret = ft_printf_fn(write_dstr, dstr, fmt, &tmp);
	va_end(tmp);
	return (ret);
}

int	ft_vsnprintf(char *str, size_t size, const char *fmt, va_list lst)
{
	va_list tmp;
	t_dstr	dest;
	int		ret;

	va_copy(tmp, lst);
	ft_bzero(&dest, sizeof(t_dstr));
	dest.cap = size;
	dest.buf = str;
	ret = ft_printf_fn(write_str, &dest, fmt, &tmp);
	va_end(tmp);
	return (ret);
}
