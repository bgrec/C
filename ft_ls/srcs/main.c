/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrec <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 14:37:49 by bgrec             #+#    #+#             */
/*   Updated: 2017/05/09 14:37:51 by bgrec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

char		g_mr_recurse;
char		g_r_reverse;
char		g_a_all;
char		g_l_metadata;
char		g_t_timesort;
char		g_f_nosort;
char		g_multiple;
char		g_printed;
char		g_sanitized;
void		(*g_sort)();
int			(*g_sort_criteria)();

static void	set_flag(char flag)
{
	if (flag == 'R')
		g_mr_recurse = 1;
	else if (flag == 'r')
		g_r_reverse = 1;
	else if (flag == 'a')
		g_a_all = 1;
	else if (flag == 'l')
		g_l_metadata = 1;
	else if (flag == 't')
		g_t_timesort = 1;
	else if (flag == 'f')
		g_f_nosort = 1;
	else
	{
		ft_putstr("ls: illegal option -- ");
		ft_putchar(flag);
		ft_putchar('\n');
		exit(-1);
	}
}

static void	set_sort_criteria(void)
{
	if (g_f_nosort)
	{
		g_sort_criteria = none;
		g_a_all = 1;
		return ;
	}
	if (g_t_timesort)
		g_sort_criteria = timestamp;
}

static void	engage(int argc, char **argv, int i)
{
	int limit;

	if (g_r_reverse && !g_f_nosort)
		g_sort = insertion_sort_rev;
	if (i < argc)
	{
		if (g_r_reverse && !g_f_nosort)
		{
			limit = i;
			i = argc;
			while (i >= limit)
				list_dir(argv[i--]);
		}
		else
			while (i < argc)
				list_dir(argv[i++]);
	}
	else
		list_dir(".");
}

int			main(int argc, char **argv)
{
	int		i;

	g_sort = insertion_sort;
	g_sort_criteria = lexicographic;
	i = 0;
	while (++i < argc && argv[i][0] == '-')
		while (*(++argv[i]))
			set_flag(*(argv[i]));
	if (argc - i > 1)
		g_multiple = 1;
	sanitize(argv + i, argc - i);
	set_sort_criteria();
	engage(argc, argv, i);
}
