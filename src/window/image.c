/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 19:27:37 by emercier          #+#    #+#             */
/*   Updated: 2026/04/04 20:04:50 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"
#include "libft.h"
#include "mlx.h"

t_point	point(int x, int y)
{
	return ((t_point){.x = x, .y = y});
}

void	put_pixel(t_image *img, int x, int y, t_color color)
{
	const size_t	offset = y * img->line_len + x * img->bytes_pp;
	const int		c = mlx_get_color_value(img->mlx, (int)color);

	if (x < 0 || x >= img->width || y < 0 || y > img->height)
		return ;
	*(unsigned int *)(img->data + offset) = c;
}

t_color	get_pixel(t_image *img, int x, int y)
{
	const size_t	offset = y * img->line_len + x * img->bytes_pp;

	if (x < 0 || x >= img->width || y < 0 || y > img->height)
		return (0);
	return (*(unsigned int *)(img->data + offset));
}

int	load_xpm_image(void *mlx, t_image *img, char *path)
{
	ft_bzero(img, sizeof(*img));
	img->ptr = mlx_xpm_file_to_image(mlx, path, &img->width, &img->height);
	if (!img->ptr)
		return (-1);
	img->data = mlx_get_data_addr(img->ptr, &img->bits_pp,
			&img->line_len, &img->endian);
	img->bytes_pp = img->bits_pp / 8;
	return (0);
}
