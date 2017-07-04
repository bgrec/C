/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_total.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrec <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 14:43:46 by bgrec             #+#    #+#             */
/*   Updated: 2017/05/09 16:06:36 by bgrec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	print_total(int total, char **entries)
{
	char	ok;
	int		i;

	i = 0;
	ok = 0;
	if (!g_a_all)
	{
		while (entries[i])
			if (entries[i++][0] != '.')
				ok = 1;
	}
	else
		ok = 1;
	if (!ok)
		return ;
	ft_putstr("total ");
	ft_putnbrendl(total);
}

void	init_struct(t_metadata *info)
{
	info->maj_cnt = 0;
	info->min_cnt = 0;
	info->total = 0;
	info->l_cnt = 0;
	info->s_cnt = 0;
	info->g_cnt = 0;
	info->n_cnt = 0;
}

void	sanitize(char **entries, int count)
{
	int		i;
	DIR		*stream;

	i = 0;
	insertion_sort(entries, count, NULL);
	while (i < count)
	{
		stream = try_opendir(entries[i]);
		if (!stream && errno == ENOENT)
			entries[i] = NULL;
		else if (stream && closedir(stream))
			ft_putendl_fd("ERROR CLOSING DIRECTORY!", 2);
		i++;
	}
	g_sanitized = 1;
}
