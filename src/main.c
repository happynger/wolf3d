/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:23:13 by otahirov          #+#    #+#             */
/*   Updated: 2019/02/12 16:19:09 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

#define MSG "\033[1;31mDESTROY\033[0m executed from ->> "
#define NAME(n) ft_strjoin("WOLF3D ->> ", n)

void			destroy(t_mlx *mlx, int line)
{
	if (mlx->win != NULL)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (mlx->fd > 2)
		close(mlx->fd);
	if (mlx->mlx != NULL)
		ft_memdel((void **)&mlx->mlx);
	if (mlx->textures != NULL)
		ft_memdel((void **)mlx->textures);
	ft_error(ft_strjoin(MSG, ft_itoa(line, 10, false)));
}

static t_mlx	*init(char *name)
{
	t_mlx	*mlx;

	CHECK_NULL(mlx = (t_mlx *)ft_memalloc(sizeof(t_mlx)));
	mlx->name = name;
	mlx->fd = open(name, O_RDONLY);
	mlx->map.blocks = NULL;
	if (mlx->fd <= 2)
		destroy(mlx, __LINE__);
	read_map(mlx);
	if (mlx->map.blocks == NULL ||
		(mlx->mlx = mlx_init()) == NULL ||
		(mlx->win = mlx_new_window(mlx->mlx, WIDTH,
			HEIGHT, NAME(name))) == NULL)
		destroy(mlx, __LINE__);
	mlx->camera.plane.x = 0;
	mlx->camera.plane.y = 0.66;
	mlx->camera.dir.x = -1;
	mlx->camera.dir.y = 0;
	mlx->camera.x = mlx->map.playerX;
	mlx->camera.y = mlx->map.playerY;
	mlx->camera.range = 100;
	mlx->frames = 0;
	return (mlx);
}

int		hook_expose(t_mlx *mlx)
{
	render(mlx);
	return (0);
}

int		main(int ac, char **av)
{
	t_mlx	*mlx;
	char	*name;

	if (ac >= 3)
	{
		ft_printf("{cyan}The wolf3d without parameters looks for ");
		ft_printf("'map.wolf' in the same directory as the executable{}\n");
		ft_error("Usage -> ./wolf3d | -> ./wolf3d [Path to the map file]");
		return (1);
	}
	else if (ac == 2)
		name = av[1];
	else
		name = ft_strdup("map.wolf");
	mlx = init(name);
	get_texture_files(mlx);
	if (mlx->textures == NULL)
		destroy(mlx, __LINE__);
	if (mlx->map.instr == -1)
		place_player(&mlx->map, mlx);
	mlx_do_key_autorepeaton(mlx->mlx);
	mlx_expose_hook(mlx->win, hook_expose, mlx);
	mlx_key_hook(mlx->win, keypress_hook, mlx);
	//mlx_hook(mlx->win, 6, 0, hook_mouse_move, mlx);
	mlx_loop(mlx->mlx);
}
