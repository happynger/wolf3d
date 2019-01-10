/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 18:07:55 by otahirov          #+#    #+#             */
/*   Updated: 2019/01/10 12:30:55 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdbool.h>
# include <stdarg.h>
# include "libft.h"
# include "structs.h"

# define INT_F(x) (x == 'i' || x == 'd' || x == 'o' || x == 'u')
# define INT_F2(x) (x == 'x' || x == 'X')
# define CHAR_F(x) (x == 'c' || x == 's')
# define REAL_F(x) (x == 'f' || x == 'F')
# define MISC_F(x) (x == 'n' || x == 'p' || x == 'b' || x == '%')
# define CONV(x) (INT_F(x) || INT_F2(x) || CHAR_F(x) || REAL_F(x) || MISC_F(x))
# define FLAGS(x) (x == '-' || x == '+' || x == ' ' || x == '0' || x == '#')
# define LENMD(x) (x == 'l' || x == 'h' || x == 'L' || x == 'z')
# define LENMOD(x) (LENMD(x) || x == 'j')
# define ALLR(x) ((REAL_F(x) || x == 'F') && g_prec == 0)
# define NEG(x, i) ((ft_atol(x) >= 0) && g_flags[i])
# define V(g) g = va_arg(ap, int)

# define CHK_NEG(x) ((**x == '-' && ft_isdigit(*(*x + 1))) || ft_isdigit(**x))
# define CHK_DIGIT(x) (CHK_NEG(x) && g_flags[6] == false && g_field == 0)
# define CHK_DGIT(x) (CHK_NEG(x) && g_flags[6] == true && g_prec == 6)
# define CHK_FLAGS(r) if (!g_flags[1] && !g_flags[3] && !g_flags[4]) return (r)
# define CHK_SIGN(f) (f[0] || (f[3] && !f[2]) || (f[1] && !f[2]))
# define CHK_RESIGN(f) (!f[0] && (f[2] || f[1]))
# define CHK_S (!CHAR_F(g_conv) && g_conv != '%') && (g_flags[1] || g_flags[3])
# define CHK_FIELD(r) ((int)ft_strlen(r) < g_field && ft_strchr(r, sign))

# define INIT_FLAGS(x) if (FLAGS(**x) && !g_flags[6]) ft_flags(x)
# define INIT_VARFD(x) else if (**x == '*' && !g_flags[6]) V(g_field)
# define INIT_FIELD(x) else if (CHK_DIGIT(x)) multidigitnb(x, true)
# define INIT_DOT(x) else if (**x == '.') g_flags[6] = true
# define INIT_VARPREC(x) else if (**x == '*' && g_flags[6]) V(g_prec)
# define INIT_PREC(x) else if (CHK_DGIT(x)) multidigitnb(x, false)
# define INIT_LENMOD(x) else if (LENMOD(**x)) *x += ft_lenmods((char *)*x)
# define PRINT(x) else g_bytes += ft_putchar(**form)
# define INIT_CONV(x) if (CONV(**x)) g_conv = **x
# define INIT_TEMP(t) else t = ft_strdup("")

# define PAD_LEFT(x, y, r) if (g_flags[0]) r = ft_strjoin(x, y)
# define PAD_RIGHT(x, y, r) else r = ft_strjoin(y, x)

# define ADD_O(t) if (g_conv == 'o') t = ft_strdup("0")
# define ADD_XS(t) else if (g_conv == 'x' && !g_flags[2]) t = ft_strdup("0x")
# define ADD_X(t) else if (g_conv == 'X' && !g_flags[2]) t = ft_strdup("0X")
# define ADD_F(t) else if (ALLR(g_conv)) t = ft_strdup(".")
# define ADD_N(t) else t = ft_strdup("")
# define ADD_P(t, r) if (NEG(r, 1)) t = ft_strdup("+")
# define ADD_S(t, r) else if (NEG(r, 3)) t = ft_strdup(" ")
# define ADD_NE(t) else t = ft_strdup("-")

# define SKIPTOC(x, c, i) while (x[i] && x[i] != c) i++

# define MAXCOLORLEN 25
# define TABLE_SIZE 14

void						ft_error(char *msg);
int							color(const char *input);
void						post(char *ret);
void						reset_glob(void);
void						ft_round(char **ret, int index);
char						*ft_inf(long double fin);
/*
**	OUTPUTS
*/
char						*print_p(va_list ap, char fg);
char						*print_u(va_list ap, char fg);
char						*print_i(va_list ap, char fg);
char						*print_s(va_list ap, char fg);
char						*print_f(va_list ap, char fg);
char						*print_m(va_list ap, char fg);

# define G_LENMOD 7
# define G_FLAGS 7

extern bool				g_flags[];
extern bool				g_lenmod[];
extern int				g_prec;
extern int				g_field;
extern int				g_bytes;
extern char				g_conv;
extern t_printf_table	g_table[];

#endif
