/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:23:36 by otahirov          #+#    #+#             */
/*   Updated: 2018/12/10 14:59:16 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct	s_printf_table
{
	char		flag;
	char		*(*func)(va_list ap, char fg);
}				t_printf_table;

typedef union	u_floating
{
	float		f;
	double		d;
	long double	ld;
}				t_floating;

#endif
