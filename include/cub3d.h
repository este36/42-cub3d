/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunari <nmunari@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 14:00:51 by nmunari           #+#    #+#             */
/*   Updated: 2026/04/28 21:57:08 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "vec2.h"
# include <fcntl.h>
# include <stdio.h>
# include "window.h"

typedef struct s_player
{
	t_vec2	pos;
	t_vec2	dir;
	double	angle;
}	t_player;

enum e_mode
{
	MODE_GAME,
	MODE_PLAYGROUND,
};

enum e_texture
{
	TEX_NORTH,
	TEX_SOUTH,
	TEX_WEST,
	TEX_EAST,
	__TEXTURES_COUNT,
	TEX_INVALID
};

typedef struct s_texture_splice
{
	t_image			*img;
	t_point			pos;
	double			y;
	double			step;
	int				target_col;
	int				target_start;
	int				target_end;
	int				target_height;
}	t_texture_splice;

typedef struct s_game
{
	t_window		*win;
	enum e_mode		mode;
	t_image			textures[__TEXTURES_COUNT];
	int				floor_color[3];
	int				ceiling_color[3];
	char			**map;
	t_player		player;
	double			fov;
	double			fov_half;
	double			fov_step;
	int				center_x;
	int				center_y;
	float			vignette[SCREEN_WIDTH * SCREEN_HEIGHT];
}	t_game;

# define STEP_SPEED		2.8
# define CELL_HEIGHT	10
# define CELL_WIDTH		10
# define SCALE			2
# define SENSITIVITY	0.0005
# define MOUSE_SPEED	3500.0
# define KEY_SPEED		4000.0

void	move_player(t_game *g, t_window *w);
void	init_fov(t_game *game);
t_point	to_screen(t_vec2 p, t_point origin, t_rectangle cell);
t_point	render_minimap(t_game *g, t_point p, double scale);
void	render_game(t_game *g);
int		render(t_window *w);
void	render_playground(t_game *g);
int		compute_vignette(t_game *g);
void	draw_vignette(t_game *g);
void	draw_scene(t_game *g);

#endif
