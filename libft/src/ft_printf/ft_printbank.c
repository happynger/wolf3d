/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbank.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 18:47:33 by otahirov          #+#    #+#             */
/*   Updated: 2018/12/12 16:28:19 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <math.h>
#include <limits.h>
#define ITOA(in) ft_itoa(in, 10, false)
#define UITOA(in) ft_uitoamax((uintmax_t)in, 10, false, true)

static long double	pullfloat(va_list ap)
{
	long double		input;

	if (g_lenmod[0])
		input = (long double)va_arg(ap, double);
	else if (g_lenmod[4])
		input = va_arg(ap, long double);
	else
		input = (long double)va_arg(ap, double);
	return (input);
}

static long			afterpointcalc(long double nb)
{
	long		ln;
	intmax_t	inb;

	inb = (intmax_t)nb;
	ln = 0;
	while ((nb - (long double)inb) > 0)
	{
		nb *= 10;
		ln++;
		inb = (int)nb;
		if (ln >= g_prec + 4)
			break ;
	}
	return (ln);
}

char				*print_f(va_list ap, char fg)
{
	intmax_t	iin;
	long double	fin;
	char		*ret;
	char		*str[2];
	long		ln;

	if (fg != 'f' && fg != 'F' && fg != 'e' && fg != 'E')
		return (NULL);
	if (isinf(fin = pullfloat(ap)) || isnan(fin))
		return (ft_inf(fin));
	iin = (intmax_t)fin;
	fin -= (float)iin;
	ret = (iin == INTMAX_MIN) ? UITOA(iin) : ITOA(iin);
	ln = afterpointcalc(fin);
	if ((g_flags[4] && g_prec == 0) || g_prec > 0)
	{
		str[0] = ft_strjoin(ret, ".");
		iin = (intmax_t)(fin * ft_pow(10, (int)ln));
		ft_strdel(&ret);
		str[1] = ft_itoa((intmax_t)iin, 10, false);
		ret = ft_strjoin(str[0], str[1]);
		ft_strdel(&str[1]);
		ft_strdel(&str[0]);
	}
	return (ret);
}

char				*print_m(va_list ap, char fg)
{
	int		*in;
	char	*ret;

	ret = ft_strnew(1);
	if (fg == '%')
		ret[0] = '%';
	else if (fg == 'n')
	{
		in = va_arg(ap, int *);
		*in = g_bytes;
	}
	return (ret);
}

char				*print_p(va_list ap, char fg)
{
	void		*ptr;
	char		*str;
	char		*temp;
	intmax_t	nb;

	if (fg != 'p')
		ft_error("Calls %p\n");
	ptr = va_arg(ap, void*);
	nb = (intmax_t)ptr;
	str = ft_itoa(nb, 16, false);
	temp = ft_strjoin("0x", str);
	ft_strdel(&str);
	str = temp;
	return (str);
}
