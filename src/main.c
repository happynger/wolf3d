/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:23:13 by otahirov          #+#    #+#             */
/*   Updated: 2019/01/10 16:17:45 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

#define MSG "\033[1;31mDIE\033[0m executed from ->> "
#define NAME(n) ft_strjoin("WOLF3D ->> ", n)

void			die(t_mlx *mlx, int line)
{
	char	*tmp;

	tmp = mlx->name;
	if (mlx->win != NULL)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (mlx->fd > 2)
		close(mlx->fd);
	if (mlx->mlx != NULL)
		ft_memdel((void **)&mlx->mlx);
	ft_error(ft_strjoin(MSG, ft_itoa(line, 10, false)));
}

static t_mlx	*init(char *name)
{
	t_mlx	*mlx;

	CHECK_NULL(mlx = (t_mlx *)ft_memalloc(sizeof(t_mlx)));
	mlx->name = name;
	mlx->fd = open(name, O_RDONLY);
	if (mlx->fd <= 2)
		die(mlx, __LINE__);
	if ((mlx->map = read_map(mlx)) == NULL ||
		(mlx->mlx = mlx_init()) == NULL ||
		(mlx->win = mlx_new_window(mlx->mlx, WIDTH,
			HEIGHT, NAME(name))) == NULL)
		die(mlx, __LINE__);
	return (mlx);
}

int		main(int ac, char **av)
{
	t_mlx	*mlx;
	char	*name;

	if (ac > 3)
		ft_error("Usage -> ./wolf3d | -> ./wolf3d [Path to the map file]");
	else if (ac == 2)
		name = av[1];
	else if (ac < 2)
		name = ft_strdup("map.wolf");
	
}
