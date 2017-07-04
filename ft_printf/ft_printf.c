/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrec <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:05:54 by bgrec             #+#    #+#             */
/*   Updated: 2017/02/23 21:27:21 by bgrec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char *format_str, ...)
{
	va_list		ap;

	va_start(ap, format_str);
	while (*format_str)
	{
		if (*format_str == '%')
			format_str += ft_lexer(format_str, ap);
		else
			ft_buffer(format_str++, CHAR);
	}
	va_end(ap);
	return (ft_buffer(format_str, READ));
}
