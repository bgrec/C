/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrec <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:09:59 by bgrec             #+#    #+#             */
/*   Updated: 2017/02/23 21:28:48 by bgrec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_unitab(int c, char *tab)
{
	int	len;

	len = 0;
	tab[len++] = 0xFC | (c >> 30);
	tab[len++] = 0x80 | ((c >> 24) & 0x3F);
	tab[len++] = 0x80 | ((c >> 18) & 0x3F);
	tab[len++] = 0x80 | ((c >> 12) & 0x3F);
	tab[len++] = 0x80 | ((c >> 6) & 0x3F);
	tab[len++] = 0x80 | (c & 0x3F);
	tab[len] = 0;
}

static int		ft_char4(int c, char *tab)
{
	int	len;

	len = 0;
	if (c < 0x200000)
	{
		tab[len++] = 0xF0 | (c >> 18);
		tab[len++] = 0x80 | ((c >> 12) & 0x3F);
		tab[len++] = 0x80 | ((c >> 6) & 0x3F);
		tab[len++] = 0x80 | (c & 0x3F);
	}
	else if (c < 0x4000000)
	{
		tab[len++] = 0xF8 | (c >> 24);
		tab[len++] = 0x80 | ((c >> 18) & 0x3F);
		tab[len++] = 0x80 | ((c >> 12) & 0x3F);
		tab[len++] = 0x80 | ((c >> 6) & 0x3F);
		tab[len++] = 0x80 | (c & 0x3F);
	}
	else
		ft_unitab(c, tab);
	tab[len] = 0;
	return (ft_buffer(tab, STR));
}

static int		ft_char2(int c, char *tab)
{
	int	len;

	len = 0;
	if (c < 0x80)
		tab[len++] = c;
	else if (c < 0x800)
	{
		tab[len++] = 0xC0 | (c >> 6);
		tab[len++] = 0x80 | (c & 0x3F);
	}
	else if (c < 0x10000)
	{
		tab[len++] = 0xE0 | (c >> 12);
		tab[len++] = 0x80 | ((c >> 6) & 0x3F);
		tab[len++] = 0x80 | (c & 0x3F);
	}
	tab[len] = 0;
	if (!tab[0])
		return (ft_buffer(tab, CHAR));
	else
		return (ft_buffer(tab, STR));
}

int				ft_wchar(int c)
{
	char	tab[10];

	if (c < 0x200000)
		return (ft_char2(c, tab));
	else
		return (ft_char4(c, tab));
}
