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
#define CLOCK_TO_SEC(time) (time / (double)CLOCKS_PER_SEC)

void	rotate(int key, t_mlx *mlx, double rs)
{
	double	dirX;
	double	planeX;

	if (key == K_D)
	{
		dirX = mlx->camera.dir.x;
		mlx->camera.dir.x = mlx->camera.dir.x * cos(-rs) -
			mlx->camera.dir.y * sin(-rs);
		mlx->camera.dir.y = dirX * sin(-rs) +
			mlx->camera.dir.y * cos(-rs);
		planeX = mlx->camera.plane.x;
		mlx->camera.plane.x = mlx->camera.plane.x * cos(-rs) -
			mlx->camera.plane.y * sin(-rs);
		mlx->camera.plane.y = planeX * sin(-rs) +
			mlx->camera.plane.y * cos(-rs);
	}
	if (key == K_A)
	{
		dirX = mlx->camera.dir.x;
		mlx->camera.dir.x = mlx->camera.dir.x * cos(rs) -
			mlx->camera.dir.y * sin(rs);
		mlx->camera.dir.y = dirX * sin(rs) +
			mlx->camera.dir.y * cos(rs);
		planeX = mlx->camera.plane.x;
		mlx->camera.plane.x = mlx->camera.plane.x * cos(rs) -
			mlx->camera.plane.y * sin(rs);
		mlx->camera.plane.y = planeX * sin(rs) +
			mlx->camera.plane.y * cos(rs);
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
	double	frametime;
	double	rotspeed;
	double	movespeed;

	if (key == K_ESC)
		exit(EXIT_SUCCESS);
	frametime = CLOCK_TO_SEC(mlx->deltaframe);
	movespeed = frametime * 5.0;
	rotspeed = frametime * 1.0;
	move(key, mlx, movespeed, rotspeed);
	render(mlx);
	return (0);
}
