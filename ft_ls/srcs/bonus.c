/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrec <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 14:26:30 by bgrec             #+#    #+#             */
/*   Updated: 2017/05/09 14:26:33 by bgrec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	other_perm(char mode, struct stat *buffer)
{
	if (mode == 0)
	{
		if (buffer->st_mode & S_ISUID)
			ft_putchar((buffer->st_mode & S_IXUSR) ? 's' : 'S');
		else
			ft_putchar((buffer->st_mode & S_IXUSR) ? 'x' : '-');
	}
	else if (mode == 1)
	{
		if (buffer->st_mode & S_ISGID)
			ft_putchar((buffer->st_mode & S_IXUSR) ? 's' : 'S');
		else
			ft_putchar((buffer->st_mode & S_IXGRP) ? 'x' : '-');
	}
	else if (mode == 2)
	{
		if (buffer->st_mode & S_ISVTX)
			ft_putchar((buffer->st_mode & S_IXUSR) ? 't' : 'T');
		else
			ft_putchar((buffer->st_mode & S_IXOTH) ? 'x' : '-');
	}
}

void	print_acl(char *filename)
{
	acl_t		acl;
	acl_entry_t	dummy;

	acl = NULL;
	acl = acl_get_link_np(filename, ACL_TYPE_EXTENDED);
	if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &dummy) == -1)
	{
		acl_free(acl);
		acl = NULL;
	}
	ft_putchar(acl ? '+' : ' ');
}
