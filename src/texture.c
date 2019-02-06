/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ori <ori@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 14:21:07 by ori               #+#    #+#             */
/*   Updated: 2019/02/05 16:20:46 by ori              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "get_next_line.h"
#include <dirent.h>

#define TXR_DIR ("./textures")

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

int			get_file(int i, char **name)
{
	struct dirent	*dp;
	DIR				*fd;
	int				count;
	int				tfd;

	if ((fd = opendir(TXR_DIR)) == NULL)
		ft_error("ERROR: Can't open directory");
	count = 0;
	while ((dp = readdir(fd)) != NULL)
	{
		if (!ft_strcmp(dp->d_name, ".") || !ft_strcmp(dp->d_name, ".."))
			continue ;
		if (count == i)
		{
			tfd = open(dp->d_name, O_RDONLY);
			*name = ft_strdup(dp->d_name);
			break ;
		}
		count++;
	}
	closedir(fd);
	return (tfd);
}

void			get_texture_files(t_mlx *mlx)
{
	int			count;
	int			i;
	t_txr		**textures;
	char		*name;

	count = get_count();
	textures = (t_txr **)ft_memalloc(count * sizeof(t_txr *));
	i = -1;
	while (++i < count)
		textures[i] = read_texture(get_file(i, &name));
}
