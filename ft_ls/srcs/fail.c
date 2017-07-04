/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fail.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrec <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 14:34:53 by bgrec             #+#    #+#             */
/*   Updated: 2017/05/09 16:10:26 by bgrec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void	print_name(const char *filename)
{
	struct stat	buf;
	char		*it;
	char		*start;

	if (stat(filename, &buf) == 0)
	{
		it = (char*)filename;
		start = it - 1;
		while (*it != 0)
		{
			if (*it == '/')
				start = it;
			it++;
		}
		ft_putstr_fd(start + 1, 2);
	}
	else
		ft_putstr_fd(filename, 2);
}

void		failsafe(const char *filename)
{
	if (errno != ENOENT && !g_sanitized)
		return ;
	ft_putstr_fd("ls: ", 2);
	print_name(filename);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putchar_fd('\n', 2);
}

char		*safejoin(char *str1, char *str2)
{
	int		len;
	int		i;
	int		j;
	char	*merged;

	len = ft_strlen(str1) + ft_strlen(str2);
	merged = malloc(sizeof(char) * (len + 2));
	i = -1;
	while (str1[++i])
		merged[i] = str1[i];
	merged[i++] = '/';
	j = 0;
	while (str2[j])
		merged[i++] = str2[j++];
	merged[i] = '\0';
	return (merged);
}
