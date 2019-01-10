/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 15:16:31 by otahirov          #+#    #+#             */
/*   Updated: 2019/01/06 13:33:00 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <math.h>

void	ft_round(char **ret, int index)
{
	char	*str;

	str = *ret;
	if (str[index] && index >= 0)
	{
		if (str[index] == '9')
		{
			str[index] = '0';
			ft_round(ret, index - 1);
		}
		else
			str[index] += (str[index + 1] >= '5'
						|| str[index + 1] == '0') ? (1) : (0);
	}
}

char	*ft_inf(long double fin)
{
	char	*ret;

	if (isnan(fin))
		ret = (ft_isupper(g_conv)) ? (ft_strdup("NAN")) : (ft_strdup("nan"));
	else
	{
		if (fin > 0)
			ret = (ft_isupper(g_conv)) ? (ft_strdup("INF")) :
			(ft_strdup("inf"));
		else
			ret = (ft_isupper(g_conv)) ? (ft_strdup("-INF")) :
			(ft_strdup("-inf"));
	}
	return (ret);
}
