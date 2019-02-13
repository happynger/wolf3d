/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 16:08:53 by ori               #+#    #+#             */
/*   Updated: 2019/02/12 18:41:46 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "get_next_line.h"

static int			get_resolution(int fd, t_txr *txr)
{
	char	*line;
	char	*tmp;
	char	**tab;
	int		ret;

	if ((ret = get_next_line(fd, &line)) != 1)
		return (1);
	tmp = line + 1;
	tab = ft_strsplit(tmp, ',');
	txr->res = ft_memalloc(2 * sizeof(* txr->res));
	txr->res[0] = ft_atoi(tab[0]) - 1;
	txr->res[1] = ft_atoi(tab[1]) - 1;
	ft_strdel(&tab[0]);
	ft_strdel(&tab[1]);
	ft_strdel(&line);
	free(tab);
	return (0);
}

static t_color		get_colors(char *pixline)
{
	char	**pixtab;
	char	*tmp;
	t_color	pixel;
	int		i;

	if (!ft_strcmp(pixline, "\n"))
		return ((t_color)0);
	pixtab = ft_strsplit(pixline, ',');
	tmp = pixtab[0] + 1;
	pixel.rgb.r = (char)ft_atoi(tmp);
	pixel.rgb.g = (char)ft_atoi(pixtab[1]);
	pixel.rgb.b = (char)ft_atoi(pixtab[2]);
	pixel.rgb.a = (char)0x00;
	i = -1;
	while (++i < 3)
		ft_strdel(&pixtab[i]);
	ft_memdel((void **)pixtab);
	return (pixel);
}

static void			get_pixels(int fd, t_txr *txr)
{
	char	*line;
	char	**pixtab;
	int		x;
	int		y;

	y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		x = -1;
		pixtab = ft_strsplit(line, ' ');
		txr->pix[y] = ft_memalloc(sizeof (t_color) * txr->res[0]);
		while (++x < txr->res[0])
		{
			txr->pix[y][x] = get_colors(pixtab[x]);
			ft_strdel(&pixtab[x]);
		}
		ft_memdel((void **)pixtab);
		ft_strdel(&line);
		y++;
	}
}

static void			*destr(t_txr *txr)
{
	if (txr != NULL)
	{
		if (txr->res != NULL)
			ft_memdel((void **)&txr->res);
		if (txr->pix != NULL)
			ft_memdel((void **)&txr->pix);
		ft_memdel((void **)&txr);
	}
	return (NULL);
}

t_txr				*read_texture(int fd, char *name)
{
	t_txr		*txr;
	static int	textureid;

	if ((txr = ft_memalloc(sizeof (t_txr))) == NULL ||
		(get_resolution(fd, txr)) == 1 ||
		(txr->pix = (t_color **)ft_memalloc(txr->res[1]
			* sizeof(t_color *))) == NULL)
		return (destr(txr));
	textureid++;
	txr->id = textureid;
	txr->name = name;
	get_pixels(fd, txr);
	close(fd);
	return (txr);
}
