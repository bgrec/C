/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrec <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 15:52:16 by bgrec             #+#    #+#             */
/*   Updated: 2017/05/09 15:59:39 by bgrec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int		none(void)
{
	return (1);
}

int		lexicographic(char *str1, char *str2)
{
	return (ft_strcmp(str1, str2));
}

int		timestamp(char *str1, char *str2, char *path)
{
	char		*path1;
	char		*path2;
	struct stat	file1;
	struct stat	file2;

	path1 = safejoin(path, str1);
	path2 = safejoin(path, str2);
	lstat(path1, &file1);
	lstat(path2, &file2);
	free(path1);
	free(path2);
	if (file2.st_mtimespec.tv_sec - file1.st_mtimespec.tv_sec == 0)
		return (ft_strcmp(str1, str2));
	else
		return (file2.st_mtimespec.tv_sec - file1.st_mtimespec.tv_sec);
}

void	insertion_sort(char **entries, int count, const char *fn)
{
	int		it;
	int		shift;
	char	*temp;

	it = 1;
	while (it < count)
	{
		shift = it;
		while (g_sort_criteria(entries[shift], entries[shift - 1], fn) < 0)
		{
			temp = entries[shift - 1];
			entries[shift - 1] = entries[shift];
			entries[shift] = temp;
			if (shift > 1)
				shift--;
		}
		it++;
	}
}

void	insertion_sort_rev(char **entries, int count, const char *fn)
{
	int		it;
	int		shift;
	char	*temp;

	it = 1;
	while (it < count)
	{
		shift = it;
		while (g_sort_criteria(entries[shift], entries[shift - 1], fn) > 0)
		{
			temp = entries[shift - 1];
			entries[shift - 1] = entries[shift];
			entries[shift] = temp;
			if (shift > 1)
				shift--;
		}
		it++;
	}
}
