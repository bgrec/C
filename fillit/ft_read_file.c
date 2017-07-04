/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrec <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 17:54:59 by bgrec             #+#    #+#             */
/*   Updated: 2017/01/17 15:17:47 by bgrec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_read_file(int fd, t_tetris *tetris)
{
	int		last_read;
	int		len;
	char	letter;
	char	buff[22];

	letter = 'A';
	last_read = -1;
	while ((len = read(fd, buff, 21)) >= 20)
	{
		last_read = len;
		if (!ft_test_tetrominoes(buff, len))
			return (0);
		*(tetris++) = ft_put_tetrominoes(buff, letter++);
	}
	if (len != 0 || last_read != 20)
		return (0);
	if (letter - 'A' > 26)
		return (0);
	else
		return (letter - 'A');
}
