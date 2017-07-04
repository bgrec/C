/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrec <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 18:34:22 by bgrec             #+#    #+#             */
/*   Updated: 2017/01/13 18:59:24 by bgrec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H
# define MAX_T 26
# include "libft.h"
# include <fcntl.h>

typedef unsigned long long	t_long;
typedef struct				s_point
{
	unsigned char x;
	unsigned char y;
}							t_point;

typedef struct				s_tetris
{
	t_long	val;
	t_point	point;
	t_point	dimension;
	char	letter;
}							t_tetris;

int							ft_test_tetrominoes(const char *str, int position);
int							ft_read_file(int fd, t_tetris *tetris);
int							ft_solve_square(t_tetris *tetris, int count,
		short *map);
void						ft_print_result(t_tetris *tetris, int count,
		int size);
t_tetris					ft_put_tetrominoes(char *str, char let);

#endif
