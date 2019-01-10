/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:23:13 by otahirov          #+#    #+#             */
/*   Updated: 2019/01/10 15:46:35 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		main(int ac, char **av)
{
	t_mlx	*mlx;
	t_map	*map;
	char	*name;

	if (ac > 3)
		ft_error("Usage -> ./wolf3d | -> ./wolf3d [Path to the map file]");
	else if (ac == 2)
		name = av[1];
	else if (ac < 2)
		name = ft_strdup("map.wolf");
	
}
