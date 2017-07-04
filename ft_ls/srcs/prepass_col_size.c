/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepass_col_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrec <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 14:38:15 by bgrec             #+#    #+#             */
/*   Updated: 2017/05/09 14:38:17 by bgrec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int			numsize(int number)
{
	int size;

	if (number == 0)
		return (1);
	size = 0;
	while (number)
	{
		size++;
		number /= 10;
	}
	return (size);
}

static void	prepass_name_group(struct stat *buffer, t_metadata *info)
{
	int				name_count;
	int				grp_count;
	struct passwd	*pw;
	struct group	*gr;

	if (!(pw = getpwuid(buffer->st_uid)))
		name_count = numsize(buffer->st_uid);
	else
		name_count = ft_strlen(pw->pw_name);
	if (!(gr = getgrgid(buffer->st_gid)))
		grp_count = numsize(buffer->st_gid);
	else
		grp_count = ft_strlen(gr->gr_name);
	if (name_count > info->n_cnt)
		info->n_cnt = name_count;
	if (grp_count > info->g_cnt)
		info->g_cnt = grp_count;
}

void		prepass_major_minor(struct stat *b, t_metadata *info)
{
	if ((b->st_mode & S_IFMT) == S_IFCHR || (b->st_mode & S_IFMT) == S_IFBLK)
	{
		if (numsize(major(b->st_rdev)) > info->maj_cnt)
			info->maj_cnt = numsize(major(b->st_rdev));
		if (numsize(minor(b->st_rdev)) > info->min_cnt)
			info->min_cnt = numsize(minor(b->st_rdev));
	}
}

void		prepass_col_size(char *filename, char *entry, t_metadata *info)
{
	struct stat	buffer;
	char		*filepath;
	int			link_count;
	int			size_count;

	if (entry[0] == '.' && !g_a_all)
		return ;
	filepath = safejoin(filename, entry);
	lstat(filepath, &buffer);
	link_count = numsize((int)(buffer.st_nlink));
	size_count = numsize((int)(buffer.st_size));
	if (link_count > info->l_cnt)
		info->l_cnt = link_count;
	if (size_count > info->s_cnt)
		info->s_cnt = size_count;
	prepass_name_group(&buffer, info);
	prepass_major_minor(&buffer, info);
	info->total += buffer.st_blocks;
	free(filepath);
}
