/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrec <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:03:06 by bgrec             #+#    #+#             */
/*   Updated: 2017/02/23 21:26:13 by bgrec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_arr_ptrfunc	g_pfunc[] =
{
	{ft_percent, '%'},
	{ft_int, 'd'},
	{ft_int, 'i'},
	{ft_uint, 'x'},
	{ft_uint, 'X'},
	{ft_uint, 'o'},
	{ft_uint, 'u'},
	{ft_long, 'D'},
	{ft_long, 'U'},
	{ft_long, 'O'},
	{ft_long, 'C'},
	{ft_long, 'S'},
	{ft_string, 's'},
	{ft_char, 'c'},
	{ft_pointer, 'p'},
	{NULL, -1}
};

static int	ft_ptrfunc(char c, va_list ap)
{
	int	i;

	i = 0;
	while (g_pfunc[i].conv != -1)
	{
		if (g_pfunc[i].conv == c)
			return (g_pfunc[i].ptrfunc(ap));
		i++;
	}
	return (1);
}

static int	ft_not_conv(t_format *format)
{
	char	arr[2];
	char	preff;

	if (!format->conversion)
		return (0);
	arr[0] = format->conversion;
	arr[1] = 0;
	if (format->ZERO)
		preff = '0';
	else
		preff = ' ';
	if (!format->MINUS)
		ft_preff(preff, format->width - 1);
	ft_buffer(arr, CHAR);
	if (format->MINUS)
		ft_preff(' ', format->width - 1);
	return (0);
}

int			ft_convertor(va_list ap, t_format *format)
{
	if (ft_ptrfunc(format->conversion, ap))
		return (ft_not_conv(format));
	return (0);
}
