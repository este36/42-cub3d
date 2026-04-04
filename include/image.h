/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 17:54:21 by emercier          #+#    #+#             */
/*   Updated: 2026/04/04 20:04:56 by emercier         ###   ########.fr       */
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

t_point	point(int x, int y);

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
}	t_rectangle;

typedef struct s_line_ctx
{
	t_point	p;
	t_point	delta;
	t_point	step;
	int		err;
	int		err_dbl;
	int		thickness;
	t_color	color;
}	t_line_ctx;

typedef struct s_line
{
	t_point	start;
	t_point	end;
}	t_line;

void	put_pixel(t_image *img, int x, int y, t_color color);
t_color	get_pixel(t_image *img, int x, int y);
int		load_xpm_image(void *mlx, t_image *img, char *path);
void	fill_rectangle(t_image *img, t_rectangle *r, t_color color);
void	draw_rectangle(t_image *img, t_rectangle *r,
			size_t thickness, t_color color);
void	draw_line(t_image *img, t_line *line, int thickness, t_color color);

#endif //  IMAGE_H
