/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 13:38:17 by otahirov          #+#    #+#             */
/*   Updated: 2019/02/12 16:09:05 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# define WIDTH 1280
# define HEIGHT 1080

# define MAX_MAP_SIZE 256

# include "../libft/includes/libft.h"
# include <stdbool.h>
# include "mlx.h"

typedef struct		s_rgba
{
	uint8_t			r;
	uint8_t			g;
	uint8_t			b;
	uint8_t			a;
}					t_rgba;

typedef union		u_color
{
	int				value;
	t_rgba			rgb;
}					t_color;

typedef struct		s_mouse
{
	int				x;
	int				x_last;
}					t_mouse;

typedef struct		s_dcoor
{
	double			x;
	double			y;
}					t_dcoor;

typedef struct		s_coor
{
	int				x;
	int				y;
}					t_coor;

typedef struct		s_camera
{
	double			x;
	double			y;
	t_dcoor			plane;
	t_dcoor			dir;
	int				range;
}					t_camera;

typedef struct		s_block
{
	t_color			color;
	bool			is_wall;
	int				value;
}					t_block;

typedef struct		s_map
{
	int				lines;
	int				maxrow;
	t_block			**blocks;
	int				playerX;
	int				playerY;
	int				row[MAX_MAP_SIZE];
	int				instr;
}					t_map;

/*
**	@cx -> x in respect to camera
**	@side_hit => 1 -> NS : => 0 -> EW
**
*/

typedef struct		s_ray
{
	double			cx;
	t_dcoor			raydir;
	t_dcoor			side;
	t_dcoor			delta;
	t_coor			step;
	bool			hit;
	bool			side_hit;
}					t_ray;

/*
**	res == (Width, Height)
**	name is allocated remember to delete!
**	pix -> pix[y][x]
*/

typedef struct		s_txr
{
	int				*res;
	t_color			**pix;
	char			*name;
	int				id;
}					t_txr;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	char			*name;
	int				fd;
	unsigned int	frames;
	int				linelength;
	t_mouse			mouse;
	t_camera		camera;
	t_txr			**textures;
	t_map			map;
}					t_mlx;

void				read_map(t_mlx *mlx);
void				render(t_mlx *mlx);
void				place_player(t_map *map, t_mlx *mlx);
void				rotate_player(t_mlx *mlx, double radians);
int					keypress_hook(int key, t_mlx *mlx);
int					hook_mouse_move(int x, int y, t_mlx *mlx);
t_txr				*read_texture(int fd, char *name);
int					get_color(int x, int y, t_mlx *mlx);
void				get_texture_files(t_mlx *mlx);

#endif
