/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrec <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:02:16 by bgrec             #+#    #+#             */
/*   Updated: 2017/02/23 21:25:58 by bgrec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write_char(va_list ap, t_format *format)
{
	int		size;
	char	tab[2];
	char	preff;
	int		wch;

	wch = va_arg(ap, int);
	tab[1] = 0;
	if (format->ZERO)
		preff = '0';
	else
		preff = ' ';
	size = format->width - 1;
	if (!format->MINUS)
		ft_preff(preff, size);
	if (format->length == 'l')
		ft_wchar(wch);
	else
	{
		tab[0] = wch;
		ft_buffer(tab, CHAR);
	}
	if (format->MINUS)
		ft_preff(' ', size);
	return (0);
}

int			ft_char(va_list ap)
{
	t_format	*format;
	char		tab[2];

	tab[1] = 0;
	format = ft_format(SET_FORMAT);
	if (!format->set)
	{
		tab[0] = va_arg(ap, int);
		ft_buffer(tab, CHAR);
	}
	else
		ft_write_char(ap, format);
	return (0);
}

int			ft_string(va_list ap)
{
	char		*str;
	t_format	*format;
	int			size;

	format = ft_format(SET_FORMAT);
	if (format->length == 'l')
		return (ft_wstring(ap, format));
	str = va_arg(ap, char *);
	if (str)
	{
		if (!*str)
			format->precision = 0;
	}
	size = ft_tmp(str, format->precision, S_JOIN);
	if (format->precision > size)
		format->precision = size;
	ft_join(format, NULL);
	return (0);
}
