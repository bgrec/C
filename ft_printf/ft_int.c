/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrec <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:03:40 by bgrec             #+#    #+#             */
/*   Updated: 2017/02/23 21:26:29 by bgrec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long			ft_read_ap(va_list ap, int flag)
{
	if (flag == 'l')
		return (va_arg(ap, long));
	else if (flag == 'L')
		return (va_arg(ap, long long));
	else if (flag == 'z')
		return (va_arg(ap, size_t));
	else if (flag == 'j')
		return (va_arg(ap, intmax_t));
	else if (flag == 'h')
		return ((short)va_arg(ap, int));
	else if (flag == 'H')
		return ((char)va_arg(ap, int));
	else
		return (va_arg(ap, int));
}

static void					ft_putsign(long long nb, t_format *format)
{
	char	*sign_preff;

	sign_preff = NULL;
	if (nb < 0)
		sign_preff = "-";
	else if (format->PLUS)
		sign_preff = "+";
	else if (format->SPACE)
		sign_preff = " ";
	ft_join(format, sign_preff);
}

int							ft_int(va_list ap)
{
	t_format			*format;
	long long			nbr;
	unsigned long long	unbr;

	format = ft_format(SET_FORMAT);
	nbr = ft_read_ap(ap, format->length);
	if (nbr < 0)
		unbr = -nbr;
	else
		unbr = nbr;
	ft_putnbr(unbr, 10, format->conversion);
	if (format->set)
	{
		if (format->ZERO && format->MINUS)
			format->ZERO = 0;
		if (format->precision != -1)
			format->ZERO = 0;
	}
	ft_putsign(nbr, format);
	return (0);
}
