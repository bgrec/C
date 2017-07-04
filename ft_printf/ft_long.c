/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrec <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:04:37 by bgrec             #+#    #+#             */
/*   Updated: 2017/02/23 21:26:55 by bgrec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_long(va_list ap)
{
	t_format	*format;

	format = ft_format(SET_FORMAT);
	format->length = 'l';
	format->set = 1;
	format->conversion = format->conversion + 32;
	return (ft_convertor(ap, format));
}
