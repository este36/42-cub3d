/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 12:17:00 by emercier          #+#    #+#             */
/*   Updated: 2026/04/04 12:32:15 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_spec.h"

int	ft_vdsprintf(t_dstr *dstr, const char *fmt, va_list lst)
{
	return (ft_printf_fn(write_dstr, dstr, fmt, &lst));
}

int	ft_vsnprintf(char *std, size_t size, const char *fmt, va_list lst)
{
	t_dstr	dest;

	ft_bzero(&dest, sizeof(t_dstr));
	dest.cap = size;
	dest.buf = str;
	return (ft_printf_fn(write_str, &dest, fmt, &lst));
}
