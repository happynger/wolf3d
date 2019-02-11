/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyvalues.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ori <ori@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 13:06:06 by otahirov          #+#    #+#             */
/*   Updated: 2019/02/03 23:40:56 by ori              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYVALUES_H
# define KEYVALUES_H

/*
**	K_NB_* -> NUMBERPAD
*/

# ifdef __unix__

#  define K_ESC			65307
#  define K_NUMLOCK		65407
#  define K_NB_MULT		65450
#  define K_NB_DIV		65455
#  define K_NB_PLUS		65451
#  define K_NB_MINUS	65453
#  define K_NB_ENTER	65421
#  define K_NB_1		65436
#  define K_NB_2		65433
#  define K_NB_3		65435
#  define K_NB_4		65430
#  define K_NB_5		65437
#  define K_NB_6		65432
#  define K_NB_7		65429
#  define K_NB_8		65431
#  define K_NB_9		65434
#  define K_NB_0		65438
#  define K_NB_DOT		65439
#  define K_UP			65362
#  define K_DOWN		65364
#  define K_LEFT		65361
#  define K_RIGHT		65363
#  define K_1			49
#  define K_2			50
#  define K_3			51
#  define K_4			52
#  define K_5			53
#  define K_6			54
#  define K_7			55
#  define K_8			56
#  define K_9			57
#  define K_0			48
#  define K_A			97
#  define K_S			115
#  define K_D			100
#  define K_F			102
#  define K_H			104
#  define K_G			103
#  define K_J			106
#  define K_K			107
#  define K_L			108
#  define K_Z			122
#  define K_X			120
#  define K_C			99
#  define K_V			118
#  define K_N			110
#  define K_M			109
#  define K_B			98
#  define K_Q			113
#  define K_W			119
#  define K_E			101
#  define K_R			114
#  define K_T			116
#  define K_Y			121
#  define K_U			117
#  define K_I			105
#  define K_O			111
#  define K_P			112
#  define K_SQBRAKETL	91
#  define K_SQBRAKETR	93
#  define K_MINUS		45
#  define K_EQUALS		61
#  define K_F1			65470
#  define K_F2			65471
#  define K_F3			65472
#  define K_F4			65473
#  define K_F5			65474
#  define K_F6			65475
#  define K_F7			65476
#  define K_F8			65477
#  define K_F9			65478
#  define K_F10			65479
#  define K_F11			65480
#  define K_F12			65481
#  define K_LAMBDA		96
#  define K_TAB			65289
#  define K_LSHIFT		65505
#  define K_RSHIFT		65506
#  define K_LCTRL		65507
#  define K_RCTRL		65508
#  define K_LCMD		65515
#  define K_RCMD		65516
#  define K_LALT		65513
#  define K_RALT		65514
#  define K_SPACE		32
#  define K_ENTER		65293
#  define K_LSLASH		47
#  define K_RSLASH		92
#  define K_BACKSPACE	65288
#  define K_QUOTES		59
#  define K_SEMICOLON	39
#  define K_COMA		44
#  define K_PERIOD		46
#  define K_MENU		65383
#  define K_PRINTSCR	65377
#  define K_SRCLOCK		65300
#  define K_PAUSE		65299
#  define K_INSERT		65379
#  define K_HOME		65360
#  define K_END			65367
#  define K_DEL			65535
#  define K_PAGEUP		65365
#  define K_PAGEDOWN	65366

# else

#  define K_ESC			53
#  define K_NUMLOCK		71
#  define K_NB_MULT		67
#  define K_NB_DIV		75
#  define K_NB_PLUS		69
#  define K_NB_MINUS	78
#  define K_NB_ENTER	76
#  define K_NB_1		83
#  define K_NB_2		84
#  define K_NB_3		85
#  define K_NB_4		86
#  define K_NB_5		87
#  define K_NB_6		88
#  define K_NB_7		89
#  define K_NB_8		91
#  define K_NB_9		92
#  define K_NB_0		82
#  define K_NB_DOT		65
#  define K_UP			126
#  define K_DOWN		125
#  define K_LEFT		123
#  define K_RIGHT		124
#  define K_1			18
#  define K_2			19
#  define K_3			20
#  define K_4			21
#  define K_5			23
#  define K_6			22
#  define K_7			26
#  define K_8			28
#  define K_9			25
#  define K_0			29
#  define K_A			0
#  define K_S			1
#  define K_D			2
#  define K_F			3
#  define K_H			4
#  define K_G			5
#  define K_J			38
#  define K_K			40
#  define K_L			37
#  define K_Z			6
#  define K_X			7
#  define K_C			8
#  define K_V			9
#  define K_N			45
#  define K_M			46
#  define K_B			11
#  define K_Q			12
#  define K_W			13
#  define K_E			14
#  define K_R			15
#  define K_T			17
#  define K_Y			16
#  define K_U			32
#  define K_I			34
#  define K_O			31
#  define K_P			35
#  define K_SQBRAKETL	33
#  define K_SQBRAKETR	30
#  define K_MINUS		27
#  define K_EQUALS		24
#  define K_F1			122
#  define K_F2			120
#  define K_F3			99
#  define K_F4			118
#  define K_F5			96
#  define K_F6			97
#  define K_F7			98
#  define K_F8			100
#  define K_F9			101
#  define K_F10			109
#  define K_F11			103
#  define K_F12			111
#  define K_LAMBDA		50
#  define K_TAB			48
#  define K_LSHIFT		257
#  define K_RSHIFT		258
#  define K_LCTRL		256
#  define K_RCTRL		269
#  define K_LCMD		259
#  define K_RCMD		260
#  define K_LALT		261
#  define K_RALT		262
#  define K_SPACE		49
#  define K_ENTER		36
#  define K_LSLASH		42
#  define K_RSLASH		44
#  define K_BACKSPACE	51
#  define K_QUOTES		41
#  define K_SEMICOLON	39
#  define K_COMA		43
#  define K_PERIOD		47
#  define K_MENU		110
#  define K_PRINTSCR	105
#  define K_SRCLOCK		107
#  define K_PAUSE		113
#  define K_INSERT		114
#  define K_HOME		115
#  define K_END			119
#  define K_DEL			117
#  define K_PAGEUP		116
#  define K_PAGEDOWN	121

# endif

#endif
