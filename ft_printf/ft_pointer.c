/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrec <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:05:27 by bgrec             #+#    #+#             */
/*   Updated: 2017/02/23 21:27:14 by bgrec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer(va_list ap)
{
	void		*addr;
	char		*pref;
	t_format	*format;

	pref = "0x";
	format = ft_format(SET_FORMAT);
	addr = va_arg(ap, void *);
	ft_putnbr((unsigned long long)addr, 16, 'x');
	ft_join(format, pref);
	return (0);
}
