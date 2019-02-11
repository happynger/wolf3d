/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ori <ori@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 00:31:30 by ori               #+#    #+#             */
/*   Updated: 2019/02/04 03:04:26 by ori              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <math.h>
#include <stdio.h>

#define DEGREES_90 1.5708

static int	get_ln(t_map *map, int y)
{
	int		i;

	i = 0;
	while (i < map->row[y])
		i++;
	return (i);
}

void		rotate_player(t_mlx *mlx, double radians)
{
	double tmpX;

	tmpX = mlx->camera.dir.x;
	mlx->camera.dir.x = mlx->camera.dir.x * cos(radians) -
		mlx->camera.dir.y * sin(radians);
	mlx->camera.dir.y = tmpX * sin(radians) +
		mlx->camera.dir.y * cos(radians);
	tmpX = mlx->camera.plane.x;
	mlx->camera.plane.x = mlx->camera.plane.x * cos(radians) -
		mlx->camera.plane.y * sin(radians);
	mlx->camera.plane.y = tmpX * sin(radians) +
		mlx->camera.plane.y * cos(radians);
}

static void	turn_player(t_mlx *mlx, int x, int y)
{
	t_map	*m;

	m = &mlx->map;
	if (y - 1 > 0 && !m->blocks[y - 1][x].is_wall)
		return ;
	else if (x + 1 < m->row[y] && !m->blocks[y][x + 1].is_wall)
		rotate_player(mlx, DEGREES_90 * -1.0);
	else if (x - 1 > 0 && !m->blocks[y][x - 1].is_wall)
		rotate_player(mlx, DEGREES_90);
	else if (y + 1 < m->lines && !m->blocks[y + 1][x].is_wall)
		rotate_player(mlx, 2.0 * DEGREES_90);
}

void		place_player(t_map *map, t_mlx *mlx)
{
	int			x;
	int			y;

	y = -1;
	while (++y < map->lines)
	{
		x = -1;
		while (++x < get_ln(map, y))
		{
			if (!map->blocks[y][x].is_wall)
			{
				map->playerX = x;
				mlx->camera.x = x;
				mlx->camera.y = y;
				map->playerY = y;
				turn_player(mlx, x, y);
				return ;
			}
		}
	}
}
