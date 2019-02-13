/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 14:21:07 by ori               #+#    #+#             */
/*   Updated: 2019/02/12 18:37:19 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "get_next_line.h"
#include <dirent.h>

#include <errno.h>
#include <string.h>

#define TXR_DIR ("../textures")

int				get_count(void)
{
	struct dirent	*dp;
	DIR				*fd;
	int				count;

	if ((fd = opendir(TXR_DIR)) == NULL)
		ft_error("ERROR: Can't open directory");
	count = 0;
	while ((dp = readdir(fd)) != NULL)
	{
		if (!ft_strcmp(dp->d_name, ".") || !ft_strcmp(dp->d_name, ".."))
			continue ;
		count++;
	}
	closedir(fd);
	return (count);
}

int				get_file(int i, char **name)
{
	struct dirent	*dp;
	DIR				*fd;
	int				count;
	int				tfd;

	if ((fd = opendir(TXR_DIR)) == NULL)
		ft_error("ERROR: Can't open directory");
	count = 0;
	tfd = 0;
	while ((dp = readdir(fd)) != NULL)
	{
		if (!ft_strcmp(dp->d_name, ".") || !ft_strcmp(dp->d_name, ".."))
			continue ;
		if (count == i)
		{
			tfd = open(ft_pathcombine(TXR_DIR, dp->d_name), O_RDONLY);
			*name = ft_strdup(dp->d_name);
			break ;
		}
		count++;
	}
	closedir(fd);
	return (tfd);
}

int				get_color(int x, int y, t_mlx *mlx)
{
	t_coor		maped;

	maped.x = x % mlx->textures[mlx->map.blocks[mlx->map.playerX]
								[mlx->map.playerY].value - 1]->res[0];
	maped.y = y % mlx->textures[mlx->map.blocks[mlx->map.playerX]
								[mlx->map.playerY].value - 1]->res[1];
	return (mlx->textures[mlx->map.blocks[mlx->map.playerX]
			[mlx->map.playerY].value - 1]->pix[maped.y][maped.x].value);
}

void			destroy_txr(t_txr **txr, int i)
{
	int		iter;
	int		y;

	iter = -1;
	while (++iter < i)
	{
		y = -1;
		while (++y < txr[iter]->res[1])
			ft_memdel((void **)&txr[iter]->pix[y]);
		ft_strdel(&txr[iter]->name);
		ft_memdel((void **)&txr[iter]);
	}
	ft_memdel((void **)txr);
	ft_printf("%s\n", strerror(errno));
}

void			get_texture_files(t_mlx *mlx)
{
	int			count;
	int			i;
	t_txr		**textures;
	char		*name;

	count = get_count();
	mlx->textures = NULL;
	if ((textures = (t_txr **)ft_memalloc(count * sizeof(t_txr *))) == NULL)
		return ;
	i = -1;
	while (++i < count)
		if ((textures[i] = read_texture(get_file(i, &name), name)) == NULL)
		{
			destroy_txr(textures, i);
			return ;
		}
	mlx->textures = textures;
}
