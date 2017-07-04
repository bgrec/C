/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_perms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrec <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 14:43:07 by bgrec             #+#    #+#             */
/*   Updated: 2017/05/09 14:43:10 by bgrec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void	show_time(struct stat *buffer)
{
	char	*time_str;
	time_t	current_time;
	int		timediff;

	time(&current_time);
	time_str = ctime(&(buffer->st_mtimespec.tv_sec));
	write(1, time_str + 4, 6);
	timediff = current_time - buffer->st_mtimespec.tv_sec;
	ft_putchar(' ');
	if (timediff < 0)
		timediff *= -1;
	if (timediff > 15552000)
	{
		ft_putchar(' ');
		write(1, time_str + 20, 4);
	}
	else
		write(1, time_str + 11, 5);
	ft_putchar(' ');
}

static void	print_usrgrp(struct stat *buffer, t_metadata *info)
{
	struct passwd	*pw;
	struct group	*gr;
	int				diff;

	if (!(pw = getpwuid(buffer->st_uid)))
		ft_putnbr(buffer->st_uid);
	else
		ft_putstr(pw->pw_name);
	if (!pw)
		diff = info->n_cnt - numsize(buffer->st_uid);
	else
		diff = info->n_cnt - ft_strlen(pw->pw_name);
	padding(diff);
	ft_putstr("  ");
	if (!(gr = getgrgid(buffer->st_gid)))
		ft_putnbr(buffer->st_gid);
	else
		ft_putstr(gr->gr_name);
	if (!gr)
		diff = info->g_cnt - numsize(buffer->st_gid);
	else
		diff = info->g_cnt - ft_strlen(gr->gr_name);
	padding(diff);
}

static void	keep_going(struct stat *b, t_metadata *info)
{
	int diff;

	diff = info->l_cnt - numsize(b->st_nlink);
	padding(diff);
	ft_putnbr((int)b->st_nlink);
	ft_putchar(' ');
	print_usrgrp(b, info);
	ft_putstr("  ");
	diff = info->s_cnt - numsize(b->st_size);
	if (info->min_cnt != 0)
		diff = info->min_cnt + info->maj_cnt - numsize(b->st_size) + 3;
	if ((b->st_mode & S_IFMT) == S_IFCHR || (b->st_mode & S_IFMT) == S_IFBLK)
		print_maj_min(b, info);
	else
	{
		padding(diff);
		ft_putnbr((int)b->st_size);
	}
	ft_putchar(' ');
	show_time(b);
}

void		list_filetype(struct stat *buffer)
{
	if ((buffer->st_mode & S_IFMT) == S_IFDIR)
		ft_putchar('d');
	else if ((buffer->st_mode & S_IFMT) == S_IFIFO)
		ft_putchar('p');
	else if ((buffer->st_mode & S_IFMT) == S_IFCHR)
		ft_putchar('c');
	else if ((buffer->st_mode & S_IFMT) == S_IFBLK)
		ft_putchar('b');
	else if ((buffer->st_mode & S_IFMT) == S_IFLNK)
		ft_putchar('l');
	else if ((buffer->st_mode & S_IFMT) == S_IFSOCK)
		ft_putchar('s');
	else if ((buffer->st_mode & S_IFMT) == S_IFWHT)
		ft_putchar('w');
	else
		ft_putchar('-');
}

char		list_perms(char *file, t_metadata *info)
{
	struct stat	buffer;
	ssize_t		buflen;

	if (lstat(file, &buffer))
		return (0);
	buflen = listxattr(file, NULL, 0, XATTR_NOFOLLOW);
	list_filetype(&buffer);
	ft_putchar((buffer.st_mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((buffer.st_mode & S_IWUSR) ? 'w' : '-');
	other_perm(0, &buffer);
	ft_putchar((buffer.st_mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((buffer.st_mode & S_IWGRP) ? 'w' : '-');
	other_perm(1, &buffer);
	ft_putchar((buffer.st_mode & S_IROTH) ? 'r' : '-');
	ft_putchar((buffer.st_mode & S_IWOTH) ? 'w' : '-');
	other_perm(2, &buffer);
	if (buflen > 0)
		ft_putchar('@');
	else
		print_acl(file);
	ft_putchar(' ');
	keep_going(&buffer, info);
	return (1);
}
