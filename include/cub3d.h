/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 18:58:22 by emercier          #+#    #+#             */
/*   Updated: 2026/04/01 19:13:30 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "libft.h"
# include "mlx.h"

typedef struct s_image
{
	void	*ptr;
	char	*data;
	int		endian;
	int		bits_pp;
	int		bytes_pp;
	int		line_len;
}	t_image;

typedef struct s_game
{
}	t_game;

#endif // CUB3D_H
