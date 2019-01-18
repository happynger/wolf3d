/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 13:20:18 by otahirov          #+#    #+#             */
/*   Updated: 2019/01/18 14:05:53 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "keyvalues.h"
#include <math.h>
#define MOUSE_TO_PLANE 10

/* int		hook_mouse_down(int button, int x, int y, t_mlx *mlx)
{

}

int		hook_mouse_up(int button, int x, int y, t_mlx *mlx)
{

}
 */

static void	mouse_rotate(t_mlx *mlx, double angle)
{
	double	dirX;
	double	planeX;

	dirX = mlx->camera.dir.x;
	mlx->camera.dir.x = mlx->camera.dir.x * cos(angle) -
		mlx->camera.dir.y * sin(angle);
	mlx->camera.dir.y = dirX * sin(angle) +
		mlx->camera.dir.y * cos(angle);
	planeX = mlx->camera.plane.x;
	mlx->camera.plane.x = mlx->camera.plane.x * cos(angle) -
		mlx->camera.plane.y * sin(angle);
	mlx->camera.plane.y = planeX * sin(angle) +
		mlx->camera.plane.y * cos(angle);
}

int			hook_mouse_move(int x, int y, t_mlx *mlx)
{
	double	angel;

	(void)y;
	mlx->mouse.x_last = mlx->mouse.x;
	if (x < 0)
		mlx->mouse.x = 0;
	else if (x > WIDTH)
		mlx->mouse.x = WIDTH;
	else
		mlx->mouse.x = x;
	angel = atan(((mlx->mouse.x_last - mlx->mouse.x) / 2) / MOUSE_TO_PLANE) * 2;
	mouse_rotate(mlx, angel);
	return (0);
}
