/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.4ms.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: ms019/01/15 16:00:40 by otahirov          #+#    #+#             */
/*   Updated: ms019/01/16 14:06:1ms by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "keyvalues.h"
#include <math.h>

#define ROT_SMOOTH 5

void	rotate(int key, t_mlx *mlx, double rs)
{
	int	i;

	i = -1;
	if (key == K_D)
		while (++i < ROT_SMOOTH)
		{
			rotate_player(mlx, -(rs / ROT_SMOOTH));
			render(mlx);
		}
	if (key == K_A)
		while (++i < ROT_SMOOTH)
		{
			rotate_player(mlx, rs / ROT_SMOOTH);
			render(mlx);
		}
}

void	move(int key, t_mlx *mlx, double ms, double rs)
{
	if (key == K_W)
	{
		if (mlx->map.blocks[(int)(mlx->camera.x + mlx->camera.dir.x *
				ms)][(int)mlx->camera.y].is_wall == false)
			mlx->camera.x += mlx->camera.dir.x * ms;
		if (mlx->map.blocks[(int)mlx->camera.x][(int)(mlx->camera.y +
				mlx->camera.dir.y * ms)].is_wall == false)
			mlx->camera.y += mlx->camera.dir.y * ms;
	}
	if (key == K_S)
	{
		if (mlx->map.blocks[(int)(mlx->camera.x - mlx->camera.dir.x *
				ms)][(int)mlx->camera.y].is_wall == false)
			mlx->camera.x -= mlx->camera.dir.x * ms;
		if (mlx->map.blocks[(int)mlx->camera.x][(int)(mlx->camera.y -
				mlx->camera.dir.y * ms)].is_wall == false)
			mlx->camera.y -= mlx->camera.dir.y * ms;
	}
	rotate(key, mlx, rs);
}

int		keypress_hook(int key, t_mlx *mlx)
{
	double	rotspeed;
	double	movespeed;

	if (key == K_ESC)
		exit(EXIT_SUCCESS);
	rotspeed = 0.17;
	movespeed = 0.3;
	move(key, mlx, movespeed, rotspeed);
	render(mlx);
	return (0);
}
