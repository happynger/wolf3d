/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ori <ori@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 11:15:16 by otahirov          #+#    #+#             */
/*   Updated: 2019/02/03 23:10:35 by ori              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	void			*p;

	p = ft_memchr(src, c, n);
	if (p != NULL)
		return (ft_mempcpy(dst, src, (p - src + 1)));
	ft_memcpy(dst, src, n);
	return (NULL);
}
