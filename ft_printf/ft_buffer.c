/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrec <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:02:03 by bgrec             #+#    #+#             */
/*   Updated: 2017/02/23 11:53:17 by bgrec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write_str(char *buf, int *size, char *str)
{
	int	i;
	int	j;

	if (!str)
		return (0);
	i = 0;
	j = *size;
	while (str[i])
	{
		if (j == BUFF_SIZE)
		{
			write(1, buf, j);
			j = 0;
		}
		buf[j++] = str[i++];
	}
	buf[j] = 0;
	*size = j;
	return (i);
}

static int	ft_write_char(char *buf, int *size, int c)
{
	int	j;

	j = *size;
	if (j == BUFF_SIZE)
	{
		write(1, buf, j);
		j = 0;
	}
	buf[j++] = c;
	*size = j;
	return (1);
}

static int	ft_copytobuf(char *buf, char *str, int size, int s)
{
	int	i;
	int	j;

	if (!str)
		str = "(null)";
	i = 0;
	j = s;
	while (!(str[i] == 0 || size == 0))
	{
		buf[j + i] = str[i];
		i++;
		size--;
	}
	buf[j + i] = 0;
	return (i);
}

int			ft_buffer(char *str, int act)
{
	static char	buf[BUFF_SIZE + 1];
	static int	size = 0;
	static int	tot = 0;
	int			i;

	i = tot;
	if (act == CHAR)
		tot += ft_write_char(buf, &size, *str);
	else if (act == STR)
		tot += ft_write_str(buf, &size, str);
	else if (act == READ)
	{
		write(1, buf, size);
		size = 0;
		i = tot;
		tot = 0;
	}
	return (i);
}

int			ft_tmp(char *str, int s, int act)
{
	static char	tmp[BUFF_SIZE + 1];
	static int	size = 0;

	if (act == S_JOIN)
		return (size += ft_copytobuf(tmp, str, s, size));
	else if (act == S_READ)
		return (size);
	else if (act == S_PRINT)
		ft_buffer(tmp, STR);
	size = 0;
	tmp[0] = 0;
	return (size);
}
