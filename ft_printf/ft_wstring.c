/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrec <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:10:08 by bgrec             #+#    #+#             */
/*   Updated: 2017/02/23 21:28:59 by bgrec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_octsize(int c)
{
	if (c < 0x80)
		return (1);
	else if (c < 0x800)
		return (2);
	else if (c < 0x10000)
		return (3);
	else if (c < 0x200000)
		return (4);
	else if (c < 0x4000000)
		return (5);
	else
		return (6);
}

static int		ft_wsprec(int *str, int prec, int *tron)
{
	int	i;
	int	j;
	int	d;
	int	tmp;

	i = 0;
	j = 0;
	tmp = 0;
	if (!str)
		return (prec);
	while (str[i])
	{
		tmp = ft_octsize(str[i]);
		if ((d = j + tmp) >= prec)
		{
			if (d == prec)
				i++;
			else
				*tron -= tmp - (d - prec);
			return (i);
		}
		j += tmp;
		i++;
	}
	return (i);
}

static int		ft_wstrlen(int *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!str)
		return (6);
	while (str[i])
		j += ft_octsize(str[i++]);
	return (j);
}

static void		ft_writews(int *str, int p, int len)
{
	if (p >= 0)
	{
		while (len--)
			ft_wchar(*str++);
	}
	else
	{
		while (*str)
			ft_wchar(*str++);
	}
}

int				ft_wstring(va_list ap, t_format *format)
{
	int		*str;
	int		prec;
	int		l_prec;
	int		len;
	char	preff;

	str = va_arg(ap, int*);
	len = ft_wstrlen(str);
	prec = (format->precision >= 0) ? format->precision : -1;
	l_prec = (prec > 0) ? ft_wsprec(str, prec, &prec) : 0;
	len = (prec >= 0 && prec < len) ? prec : len;
	preff = (format->ZERO) ? '0' : ' ';
	if (!format->MINUS)
		ft_preff(preff, format->width - len);
	if (!str)
		ft_buffer("(null)", STR);
	else
		ft_writews(str, prec, l_prec);
	if (format->MINUS)
		ft_preff(' ', format->width - len);
	return (0);
}
