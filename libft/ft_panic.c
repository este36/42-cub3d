/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_panic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 17:21:37 by emercier          #+#    #+#             */
/*   Updated: 2026/04/02 17:32:27 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_ops.h"
#include "ft_printf_spec.h"
#include <unistd.h>

void	ft_panic(char *fmt, ...)
{
	va_list	arg_list;
	int fd;

	fd = 2;
	va_start(arg_list, fmt);
	ft_printf_fn(write_fd, &fd, fmt, &arg_list);
	va_end(arg_list);
	exit(1);
}
