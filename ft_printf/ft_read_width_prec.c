/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_width_prec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrec <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:07:55 by bgrec             #+#    #+#             */
/*   Updated: 2017/02/23 21:28:21 by bgrec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_read_width(char *arg, va_list ap, t_format *format)
{
	char	*tmp;
	int		nbr;

	tmp = arg;
	if (*tmp == '*' || (*tmp >= '0' && *tmp <= '9'))
	{
		if (*tmp == '*' && arg++)
		{
			nbr = va_arg(ap, int);
			if (nbr < 0)
			{
				nbr = -nbr;
				format->MINUS = 1;
			}
			format->width = nbr;
		}
		else
			format->width = ft_atoi(&arg);
		if (format->width)
			format->set = 1;
	}
	return (arg - tmp);
}

int	ft_read_precision(char *arg, va_list ap, t_format *format)
{
	char	*tmp;
	int		nb;

	tmp = arg;
	if (*arg == '.')
	{
		arg++;
		if (*arg == '*' && arg++)
		{
			nb = va_arg(ap, int);
			if (nb > 0)
				format->set = 1;
			if (nb < 0)
				nb = format->precision;
			format->precision = nb;
		}
		else
		{
			format->precision = ft_atoi(&arg);
			format->set = 1;
		}
	}
	return (arg - tmp);
}
