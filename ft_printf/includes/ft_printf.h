/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrec <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:10:26 by bgrec             #+#    #+#             */
/*   Updated: 2017/02/28 16:46:30 by bgrec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <inttypes.h>
# include <unistd.h>

# define CLEAR_FORMAT	0
# define SET_FORMAT		1
# define HASH			flag[0]
# define MINUS			flag[1]
# define PLUS			flag[2]
# define SPACE			flag[3]
# define ZERO			flag[4]
# define S_READ			0
# define S_JOIN			1
# define S_PRINT		2
# define NBR_SIZE		31
# define READ           1
# define STR            2
# define CHAR           4
# define BUFF_SIZE		15000

typedef struct	s_format
{
	int			flag[5];
	int			width;
	int			precision;
	char		length;
	char		conversion;
	int			set;
}				t_format;

typedef struct	s_ptrfunc
{
	int			(*ptrfunc)(va_list);
	char		conv;
}				t_arr_ptrfunc;

int				ft_printf(char *str, ...);
void			ft_preff(char c, int a);
t_format		*ft_format(int action);
int				ft_read_flags(char *arg, t_format *format);
int				ft_read_width(char *a, va_list ap, t_format *f);
int				ft_read_length(char *arg, t_format *format);
int				ft_read_precision(char *a, va_list ap, t_format *f);
int				ft_read_conversion(char *arg, t_format *format);
int				ft_long(va_list ap);
int				ft_tmp(char *str, int size, int act);
int				ft_join(t_format *format, char *sign);
int				ft_atoi(char **arg);
int				ft_buffer(char *str, int act);
int				ft_lexer(char *str, va_list ap);
int				ft_int(va_list ap);
int				ft_uint(va_list ap);
int				ft_percent(va_list ap);
int				ft_string(va_list ap);
int				ft_char(va_list ap);
int				ft_wchar(int c);
int				ft_pointer(va_list ap);
int				ft_wstring(va_list ap, t_format *format);
int				ft_convertor(va_list ap, t_format *f);
int				ft_putnbr(unsigned long long n, int b, int c);

#endif
