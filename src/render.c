/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 14:04:54 by otahirov          #+#    #+#             */
/*   Updated: 2019/01/14 15:54:36 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	render(t_mlx *mlx)
{
	int			x;
	double		cx;
	t_vector	ray;

	x = 0;
	while (x < WIDTH)
	{
		cx = 2 * x / (double)WIDTH - 1;
		ray.s = mlx->camera.dir.s + mlx->camera.plane.s * cx;
		ray.e = mlx->camera.dir.e + mlx->camera.plane.e * cx;
	}
}
