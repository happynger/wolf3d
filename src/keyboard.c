/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 16:00:40 by otahirov          #+#    #+#             */
/*   Updated: 2019/01/15 17:10:32 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "keyvalues.h"
#include <math.h>

void	rotate(int key, t_mlx *mlx, double rot_speed)
{
	t_dcoor	dir;
	t_dcoor	plane;

	if (key == D)
	{
		dir.x = mlx->camera.dir.x;
		mlx->camera.dir.x = mlx->camera.dir.x * cos(-rot_speed) -
			mlx->camera.dir.y * sin(-rot_speed);
		mlx->camera.dir.y = dir.x * cos(-rot_speed) +
			mlx->camera.dir.y * sin(-rot_speed);
		plane.x = mlx->camera.plane.x;
		mlx->camera.plane.x = mlx->camera.plane.x * cos(-rot_speed) -
			mlx->camera.plane.y * sin(-rot_speed);
		mlx->camera.plane.y = plane.x * cos(-rot_speed) +
			mlx->camera.plane.y * sin(-rot_speed);
	}
	if (key == A)
	{
		dir.x = mlx->camera.dir.x;
		mlx->camera.dir.x = mlx->camera.dir.x * cos(rot_speed) -
			mlx->camera.dir.y * sin(rot_speed);
		mlx->camera.dir.y = dir.x * cos(rot_speed) +
			mlx->camera.dir.y * sin(rot_speed);
		plane.x = mlx->camera.plane.x;
		mlx->camera.plane.x = mlx->camera.plane.x * cos(rot_speed) -
			mlx->camera.plane.y * sin(rot_speed);
		mlx->camera.plane.y = plane.x * cos(rot_speed) +
			mlx->camera.plane.y * sin(rot_speed);
	}
}

void	move(int key, t_mlx *mlx, double move_speed, double rot_speed)
{
	if (key == W)
	{
		if (mlx->map.blocks[(int)(mlx->camera.x + mlx->camera.dir.x *
				move_speed)][(int)mlx->camera.y].is_wall == false)
			mlx->camera.x += mlx->camera.dir.x * move_speed;
		if (mlx->map.blocks[(int)mlx->camera.x][(int)(mlx->camera.y +
				mlx->camera.dir.y * move_speed)].is_wall == false)
			mlx->camera.y += mlx->camera.dir.y * move_speed;
	}
	if (key == S)
	{
		if (mlx->map.blocks[(int)(mlx->camera.x - mlx->camera.dir.x *
				move_speed)][(int)mlx->camera.y].is_wall == false)
			mlx->camera.x -= mlx->camera.dir.x * move_speed;
		if (mlx->map.blocks[(int)mlx->camera.x][(int)(mlx->camera.y -
				mlx->camera.dir.y * move_speed)].is_wall == false)
			mlx->camera.y -= mlx->camera.dir.y * move_speed;
	}
	rotate(key, mlx, rot_speed);
}

int		keypress_hook(int key, t_mlx *mlx)
{
	double	frame_rate;
	double	move_speed;
	double	rot_speed;

	if (key == ESC)
		exit(EXIT_SUCCESS);
	frame_rate = (mlx->curframe - mlx->prevframe) / 1000.0;
	move_speed = frame_rate * 4.0;
	rot_speed = frame_rate * 2.0;
	move(key, mlx, move_speed, rot_speed);
	render(mlx);
	return (0);
}
