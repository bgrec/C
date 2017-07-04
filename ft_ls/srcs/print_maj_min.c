/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_maj_min.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrec <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 14:39:19 by bgrec             #+#    #+#             */
/*   Updated: 2017/05/09 16:07:44 by bgrec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	print_maj_min(struct stat *b, t_metadata *info)
{
	int	diff;

	ft_putchar(' ');
	diff = info->maj_cnt - numsize(major(b->st_rdev));
	padding(diff);
	ft_putnbr(major(b->st_rdev));
	ft_putstr(", ");
	diff = info->min_cnt - numsize(minor(b->st_rdev));
	padding(diff);
	ft_putnbr(minor(b->st_rdev));
}

void	print_link(char *merged, char *buffer)
{
	if (readlink(merged, buffer, 4096) != -1)
	{
		ft_putstr(" -> ");
		ft_putstr(buffer);
	}
}

void	padding(int size)
{
	while (size--)
		ft_putchar(' ');
}

DIR		*try_opendir(const char *filename)
{
	DIR		*stream;

	stream = opendir(filename);
	if (stream == NULL)
		failsafe(filename);
	return (stream);
}
