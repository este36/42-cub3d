/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 17:54:21 by emercier          #+#    #+#             */
/*   Updated: 2026/04/03 18:58:23 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include <stdint.h>
# include <stddef.h>

typedef uint32_t	t_color;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_image
{
	void	*mlx;
	void	*ptr;
	char	*data;
	int		width;
	int		height;
	int		endian;
	int		bits_pp;
	int		bytes_pp;
	int		line_len;
}	t_image;

typedef struct s_rectangle
{
	t_point	pos;
	int		width;
	int		height;
	t_color	color;
}	t_rectangle;

typedef struct s_line_ctx
{
	t_point	p;
	t_point	delta;
	t_point	step;
	int		err;
	int		err_dbl;
}	t_line_ctx;

typedef struct s_line
{
	t_point	start;
	t_point	end;
	int		thickness;
	t_color	color;
}	t_line;

void	put_pixel(t_image *img, int x, int y, t_color color);
void	draw_rectangle(t_image *img, t_rectangle *rectangle);
void	draw_line(t_image *img, t_line *line);

#endif //  IMAGE_H
