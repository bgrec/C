/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entries.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrec <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 14:27:02 by bgrec             #+#    #+#             */
/*   Updated: 2017/05/09 16:12:21 by bgrec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

char	**get_entries(const char *filename)
{
	int				file_count;
	int				i;
	char			**entries;
	DIR				*stream;
	struct dirent	*dir;

	if ((file_count = get_entry_count(filename)) == -1)
		return (NULL);
	if (!(entries = malloc(sizeof(char*) * (file_count + 1))))
		return (NULL);
	if (!(stream = try_opendir(filename)))
	{
		free(entries);
		return (NULL);
	}
	i = 0;
	while ((dir = readdir(stream)) && i < file_count)
		entries[i++] = ft_strdup(dir->d_name);
	if (closedir(stream))
		ft_putendl_fd("ERROR CLOSING DIRECTORY!", 2);
	entries[i] = NULL;
	g_sort(entries, file_count, filename);
	return (entries);
}

int		get_entry_count(const char *filename)
{
	DIR				*stream;
	struct dirent	*dir;
	int				count;

	if (!(stream = try_opendir(filename)))
		return (-1);
	count = 0;
	while ((dir = readdir(stream)))
		count++;
	if (closedir(stream))
		ft_putendl_fd("ERROR CLOSING DIRECTORY!", 2);
	return (count);
}
