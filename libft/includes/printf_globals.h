/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_globals.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 11:03:29 by otahirov          #+#    #+#             */
/*   Updated: 2019/01/31 15:09:20 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_GLOBALS_H
# define PRINTF_GLOBALS_H

# include "structs.h"

extern bool				g_flags[];
extern bool				g_lenmod[];
extern int				g_prec;
extern int				g_field;
extern int				g_bytes;
extern char				g_conv;
extern t_printf_table	g_table[];

#endif
