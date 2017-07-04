/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_result.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrec <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 19:43:49 by bgrec             #+#    #+#             */
/*   Updated: 2017/01/12 19:45:22 by bgrec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static inline char	*ft_generate_map(int size)
{
	char	*str;
	t_point	point;

	str = ft_strnew((size + 1) * size);
	point.y = 0;
	while (point.y < size)
	{
		point.x = 0;
		while (point.x < size)
		{
			str[point.y * (size + 1) + point.x] = '.';
			point.x++;
		}
		str[point.y * (size + 1) + point.x] = '\n';
		point.y++;
	}
	return (str);
}

void				ft_print_result(t_tetris *tetro, int count, int size)
{
	char	*str;
	t_point	point;

	str = ft_generate_map(size);
	while (count > 0)
	{
		point.y = 0;
		while (point.y < tetro->dimension.y)
		{
			point.x = 0;
			while (point.x < tetro->dimension.x)
			{
				if ((tetro->val >> (16 * (point.y + 1) - 1 - point.x)) & 1)
					str[(tetro->point.y + point.y) * (size + 1) + point.x +
						tetro->point.x] = tetro->letter;
				point.x++;
			}
			point.y++;
		}
		tetro++;
		count--;
	}
	ft_putstr(str);
	ft_strdel(&str);
}
