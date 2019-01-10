/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 13:38:17 by otahirov          #+#    #+#             */
/*   Updated: 2019/01/10 15:46:47 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# define WIDTH 1280
# define HEIGHT 1080

# include "libft.h"
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
	char			is_down;
	int				x;
	int				y;
	int				x_last;
	int				y_last;
}					t_mouse;

typedef struct		s_vector
{
	double			s;
	double			e;
}					t_vector;

typedef struct		s_camera
{
	t_vector		pos;
	t_vector		plane;
	t_vector		dir;
}					t_camera;

typedef struct		s_map
{
	int				x;
	int				y;
	bool			is_a_wall;
}					t_map;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	t_mouse			mouse;
	t_camera		camera;
	t_map			*map;
}					t_mlx;



#endif
