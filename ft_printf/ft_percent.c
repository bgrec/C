/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrec <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:05:05 by bgrec             #+#    #+#             */
/*   Updated: 2017/02/23 21:27:05 by bgrec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_percent(va_list ap)
{
	t_format	*format;
	char		preff;

	(void)ap;
	format = ft_format(SET_FORMAT);
	if (format->ZERO)
		preff = '0';
	else
		preff = ' ';
	if (!format->MINUS)
		ft_preff(preff, format->width - 1);
	ft_buffer("%", STR);
	if (format->MINUS)
		ft_preff(' ', format->width - 1);
	return (0);
}
