/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 17:54:21 by emercier          #+#    #+#             */
/*   Updated: 2026/04/02 18:34:11 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include <stdint.h>
# include <stdlib.h>

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_image
{
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
	int		color;
}	t_rectangle;

typedef struct s_line
{
	t_point start;
	t_point	end;
	int		thickness;
	int		color;
}	t_line;

void	put_pixel(t_image *i, int x, int y, int color);
void	draw_rectangle(t_image *i, t_rectangle *rectangle);
void	draw_line(t_image *i, t_line *line);

#endif //  IMAGE_H
