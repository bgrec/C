/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrec <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:09:10 by bgrec             #+#    #+#             */
/*   Updated: 2017/02/23 21:28:36 by bgrec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned long long	ft_castap(va_list ap, int length)
{
	if (length == 'L')
		return (va_arg(ap, unsigned long long));
	else if (length == 'j')
		return (va_arg(ap, uintmax_t));
	else if (length == 'z')
		return (va_arg(ap, ssize_t));
	else if (length == 'l')
		return (va_arg(ap, unsigned long int));
	else if (length == 'h')
		return ((unsigned short)va_arg(ap, unsigned int));
	else if (length == 'H')
		return ((unsigned char)va_arg(ap, unsigned int));
	else
		return (va_arg(ap, unsigned int));
}

static void					u_write(unsigned long long n, t_format *f)
{
	char	*sign;
	int		size;

	sign = NULL;
	if (n)
	{
		if (f->conversion == 'x' && f->HASH)
			sign = "0x";
		else if (f->conversion == 'X' && f->HASH)
			sign = "0X";
		else if (f->conversion == 'o' && f->HASH)
		{
			size = ft_tmp(NULL, 0, S_READ);
			if (f->precision <= size)
				sign = "0";
		}
	}
	ft_join(f, sign);
}

int							ft_uint(va_list ap)
{
	unsigned long long	nbr;
	t_format			*format;
	int					base;

	format = ft_format(SET_FORMAT);
	nbr = ft_castap(ap, format->length);
	if (format->conversion == 'x' || format->conversion == 'X')
		base = 16;
	else if (format->conversion == 'o')
		base = 8;
	else
		base = 10;
	ft_putnbr(nbr, base, format->conversion);
	if (format->set)
	{
		if (format->ZERO && format->MINUS)
			format->ZERO = 0;
		if (format->precision != -1)
			format->ZERO = 0;
	}
	u_write(nbr, format);
	return (0);
}
