/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrec <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 14:38:42 by bgrec             #+#    #+#             */
/*   Updated: 2017/05/09 14:38:50 by bgrec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void	format_entry(char *name, char *dir_prefix, t_metadata *info)
{
	char *merged;
	char buffer[4096];

	merged = NULL;
	if (!g_a_all && name[0] == '.')
		return ;
	if (g_l_metadata)
	{
		merged = safejoin(dir_prefix, name);
		if (!list_perms(merged, info))
		{
			failsafe(merged);
			return ;
		}
	}
	ft_putstr(name);
	ft_memset(buffer, 0, 4096);
	print_link(merged, (char*)buffer);
	ft_putchar('\n');
	if (merged)
		free(merged);
	if (!g_mr_recurse)
		free(name);
}

static void	print_dirname(const char *filename)
{
	if (g_printed)
		ft_putchar('\n');
	if (filename[0] == '/' && filename[1] == '/' && filename[2] != '/')
		filename++;
	ft_putstr(filename);
	ft_putendl(":");
	if (g_printed == 0)
		g_printed = 1;
}

static char	is_recursable(char **entry, char *filename)
{
	struct stat	buffer;
	char		*merged;

	if (*entry[0] == '.' && !g_a_all)
		return (0);
	merged = safejoin(filename, *entry);
	free(*entry);
	lstat(merged, &buffer);
	if (S_ISDIR(buffer.st_mode) && !S_ISLNK(buffer.st_mode)
			&& !ft_strequ(*entry, ".") && !ft_strequ(*entry, ".."))
	{
		*entry = merged;
		return (1);
	}
	else
		return (0);
}

static void	init_recursivity(char **entries, char *filename)
{
	int i;

	i = -1;
	while (entries[++i])
		if (is_recursable(&entries[i], filename))
		{
			if (!g_multiple)
				print_dirname(entries[i]);
			list_dir(entries[i]);
			free(entries[i]);
		}
}

void		list_dir(char *filename)
{
	char		**entries;
	t_metadata	info;
	int			i;

	if (!filename)
		return ;
	if (g_multiple)
		print_dirname(filename);
	if ((entries = get_entries(filename)) == NULL)
		return ;
	i = 0;
	if (g_l_metadata)
		init_struct(&info);
	while (g_l_metadata && entries[i])
		prepass_col_size(filename, entries[i++], &info);
	if (g_l_metadata)
		print_total(info.total, entries);
	i = 0;
	while (entries[i])
		format_entry(entries[i++], filename, &info);
	g_printed = 1;
	if (g_mr_recurse)
		init_recursivity(entries, filename);
	free(entries);
}
