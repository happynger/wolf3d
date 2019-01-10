/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 13:38:17 by otahirov          #+#    #+#             */
/*   Updated: 2019/01/10 13:47:30 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# define WIDTH 1280
# define HEIGHT 1080

# include "libft.h"

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

typedef struct		s_player
{
	double			x;
	double			y;
	float			rayX;
	float			rayY;
}					t_player;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	t_mouse			mouse;
}					t_mlx;

#endif
