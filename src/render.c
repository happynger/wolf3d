/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ori <ori@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 14:04:54 by otahirov          #+#    #+#             */
/*   Updated: 2019/02/05 14:49:01 by ori              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <math.h>

static void	dda(t_mlx *mlx, t_ray *ray)
{
	int		i;

	i = 0;
	while (ray->hit == false && i < mlx->camera.range)
	{
		if (ray->side.x < ray->side.y)
		{
			ray->side.x += ray->delta.x;
			mlx->map.playerX += ray->step.x;
			ray->side_hit = false;
		}
		else
		{
			ray->side.y += ray->delta.y;
			mlx->map.playerY += ray->step.y;
			ray->side_hit = true;
		}
		if (mlx->map.blocks[mlx->map.playerX][mlx->map.playerY].is_wall)
			ray->hit = true;
		i++;
	}
}

static void	init_ray(t_ray *ray, t_mlx *mlx)
{
	ray->hit = false;
	ray->delta.x = fabs(1 / ray->raydir.x);
	ray->delta.y = fabs(1 / ray->raydir.y);
	if (ray->raydir.x < 0)
	{
		ray->step.x = -1;
		ray->side.x = (mlx->camera.x - mlx->map.playerX) * ray->delta.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side.x = (mlx->map.playerX + 1.0 - mlx->camera.x) * ray->delta.x;
	}
	if (ray->raydir.y < 0)
	{
		ray->step.y = -1;
		ray->side.y = (mlx->camera.y - mlx->map.playerY) * ray->delta.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side.y = (mlx->map.playerY + 1.0 - mlx->camera.y) * ray->delta.y;
	}
}

static void	draw(t_mlx *mlx, int x)
{
	int			y;
	int			blank;

	y = 0;
	blank = (HEIGHT - mlx->linelength) / 2;
	while (y < HEIGHT)
	{
		if (y < blank)
			mlx_pixel_put(mlx->mlx, mlx->win, x, y, 0x65BEE5);
		else if (y > blank + mlx->linelength)
			mlx_pixel_put(mlx->mlx, mlx->win, x, y, 0x656EE5);
		else
			mlx_pixel_put(mlx->mlx, mlx->win, x, y, 0x210E40);
		y++;
	}
}

static void	init(t_mlx *mlx, t_ray *ray, int x)
{
	mlx->map.playerX = mlx->camera.x;
	mlx->map.playerY = mlx->camera.y;
	ray->cx = 2.0 * x / (double)WIDTH - 1.0;
	ray->raydir.x = mlx->camera.dir.x + mlx->camera.plane.x * ray->cx;
	ray->raydir.y = mlx->camera.dir.y + mlx->camera.plane.y * ray->cx;
	init_ray(ray, mlx);
	dda(mlx, ray);
}

void		render(t_mlx *mlx)
{
	int			x;
	t_ray		ray;
	double		wall_dist;

	x = -1;
	while (++x < WIDTH)
	{
		init(mlx, &ray, x);
		if (!ray.side_hit)
			wall_dist = (mlx->map.playerX - mlx->camera.x +
				(1 - ray.step.x) / 2) / ray.raydir.x;
		else
			wall_dist = (mlx->map.playerY - mlx->camera.y +
				(1 - ray.step.y) / 2) / ray.raydir.y;
		mlx->linelength = (ray.hit) ? HEIGHT / wall_dist : HEIGHT;
		draw(mlx, x);
	}
	mlx->frames++;
}
