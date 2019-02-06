/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ori <ori@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 16:08:53 by ori               #+#    #+#             */
/*   Updated: 2019/02/05 16:30:08 by ori              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "get_next_line.h"

int			*get_resolution(int fd)
{
	char	*line;
	char	**tab;
	int		i[2];

	if (get_next_line(fd, &line) != 0)
		return (NULL);
	line++;
	tab = ft_strsplit(line, ',');
	i[0] = ft_atoi(tab[0]);
	i[1] = ft_atoi(tab[1]);
	ft_strdel(&tab[0]);
	ft_strdel(&tab[1]);
	free(tab);
	return (i);
}

void		get_pixels(int fd)
{
	
}

t_txr		*read_texture(int fd)
{
	char	*line;
	t_txr	txr;
	int		x;

	txr.res = get_resolution(fd);
	txr.pix = (t_color **)ft_memalloc(txr.res[1] * sizeof(t_color *));

	close(fd);
}
