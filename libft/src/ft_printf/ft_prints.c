/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 11:54:30 by otahirov          #+#    #+#             */
/*   Updated: 2019/01/31 11:06:31 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "printf_globals.h"

#define FT_ITOA(is_upper) (ft_itoa(input, base, is_upper))
#define FT_UITOA(is_upper) (ft_uitoa(uinput, base, is_upper))

static intmax_t		pulldata(va_list ap)
{
	intmax_t		input;
	short int		si;
	signed char		sc;

	if (g_lenmod[0])
		input = (intmax_t)va_arg(ap, long);
	else if (g_lenmod[1])
		input = (intmax_t)va_arg(ap, long long);
	else if (g_lenmod[2])
	{
		si = (short int)va_arg(ap, int);
		input = (intmax_t)si;
	}
	else if (g_lenmod[3])
	{
		sc = (signed char)va_arg(ap, int);
		input = (intmax_t)sc;
	}
	else if (g_lenmod[5])
		input = va_arg(ap, intmax_t);
	else if (g_lenmod[6])
		input = (intmax_t)va_arg(ap, size_t);
	else
		input = (intmax_t)va_arg(ap, int);
	return (input);
}

static uintmax_t	pulludata(va_list ap)
{
	uintmax_t				input;
	unsigned short int		si;
	unsigned char			uc;

	if (g_lenmod[0])
		input = (uintmax_t)va_arg(ap, unsigned long);
	else if (g_lenmod[1])
		input = (uintmax_t)va_arg(ap, unsigned long long);
	else if (g_lenmod[2])
	{
		si = (unsigned short int)va_arg(ap, int);
		input = (uintmax_t)si;
	}
	else if (g_lenmod[3])
	{
		uc = (unsigned int)va_arg(ap, int);
		input = (uintmax_t)uc;
	}
	else if (g_lenmod[5])
		input = va_arg(ap, uintmax_t);
	else if (g_lenmod[5])
		input = (uintmax_t)va_arg(ap, size_t);
	else
		input = (uintmax_t)va_arg(ap, unsigned int);
	return (input);
}

char				*print_i(va_list ap, char fg)
{
	intmax_t	input;
	uintmax_t	uinput;
	int			base;
	char		*str;

	base = 10;
	if (fg == 'b')
		base = 2;
	input = pulldata(ap);
	if ((g_prec == 0 || (g_prec == 6 && g_flags[6])) && input == 0)
	{
		g_flags[2] = false;
		return (ft_strnew(1));
	}
	if (g_prec != 6 && g_flags[6])
		g_flags[2] = false;
	if (input <= INTMAX_MIN)
	{
		uinput = (uintmax_t)input;
		str = (ft_isupper(fg)) ? (FT_UITOA(true)) : (FT_UITOA(false));
		ft_strshift(&str, 1, '-');
	}
	else
		str = (ft_isupper(fg)) ? (FT_ITOA(true)) : (FT_ITOA(false));
	return (str);
}

char				*print_u(va_list ap, char fg)
{
	uintmax_t	uinput;
	char		*str;
	int			base;

	base = 10;
	if (fg == 'o')
		base = 8;
	else if (fg == 'x' || fg == 'X')
		base = 16;
	uinput = pulludata(ap);
	if (uinput == 0)
	{
		g_flags[4] = (fg == 'o' && g_flags[4]) ? true : false;
		if (g_prec <= 0 || (g_prec == 6 && g_flags[6]))
		{
			g_flags[2] = false;
			if (g_prec < 0)
				g_field = 1;
			return (ft_strnew(1));
		}
	}
	str = (ft_isupper(fg)) ? (FT_UITOA(true)) : (FT_UITOA(false));
	return (str);
}

char				*print_s(va_list ap, char fg)
{
	char	*str;
	char	c;

	if (fg == 's')
	{
		str = va_arg(ap, char *);
		str = (str == NULL) ? (ft_strdup("(null)")) : (ft_strdup(str));
	}
	else
	{
		c = va_arg(ap, int);
		if (c == 0)
		{
			str = ft_strdup("^@");
			g_bytes -= 1;
			g_field += 1;
		}
		else
		{
			str = ft_strnew(1);
			str[0] = c;
		}
	}
	return (str);
}
