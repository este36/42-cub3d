/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 20:51:34 by emercier          #+#    #+#             */
/*   Updated: 2026/04/02 20:57:43 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"
#include "mlx.h"

void	put_pixel(t_image *img, int x, int y, t_color color)
{
	const size_t	offset = y * img->line_len + x * img->bytes_pp;
	const int		c = mlx_get_color_value(img->mlx, (int)color);

	*(unsigned int *)(img->data + offset) = c;
}
