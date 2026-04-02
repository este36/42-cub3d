/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunari <nmunari@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:58:14 by nmunari           #+#    #+#             */
/*   Updated: 2025/12/21 21:30:46 by nmunari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "../libft.h"

int		ft_printf(const char *str, ...);
ssize_t	ft_putchar(char c);
ssize_t	ft_putstr(char *str);
ssize_t	puthexa(unsigned long n, int up_case);
ssize_t	ft_putptr(void *ptr);
ssize_t	ft_putnbr(long n);

#endif
