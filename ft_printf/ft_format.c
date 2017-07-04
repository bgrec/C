/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrec <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:03:28 by bgrec             #+#    #+#             */
/*   Updated: 2017/02/23 21:26:21 by bgrec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_init(t_format *temp)
{
	int	i;

	i = 0;
	while (i < 5)
		temp->flag[i++] = 0;
	temp->width = 0;
	temp->precision = -1;
	temp->length = '0';
	temp->conversion = 0;
	temp->set = 0;
}

t_format	*ft_format(int action)
{
	static t_format	temp;

	if (action == CLEAR_FORMAT)
		ft_init(&temp);
	return (&temp);
}

void		ft_preff(char c, int a)
{
	int	i;

	if (a > 0)
	{
		i = 0;
		while (i++ < a)
			ft_buffer(&c, CHAR);
	}
}

static int	ft_write_format(char *str, va_list ap, t_format *format)
{
	int	ok;
	int	i;
	int	j;

	ok = 1;
	i = 1;
	while (ok)
	{
		j = 0;
		if (j += ft_read_flags(str + i, format))
			i += j;
		else if (j += ft_read_width(str + i, ap, format))
			i += j;
		else if (j += ft_read_precision(str + i, ap, format))
			i += j;
		else if (j += ft_read_length(str + i, format))
			i += j;
		else
			ok = 0;
	}
	i += ft_read_conversion(str + i, format);
	return (i);
}

int			ft_lexer(char *str, va_list ap)
{
	t_format	*format;
	int			i;

	format = ft_format(CLEAR_FORMAT);
	i = ft_write_format(str, ap, format);
	ft_convertor(ap, format);
	ft_format(CLEAR_FORMAT);
	return (i);
}
