/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrec <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 14:53:52 by bgrec             #+#    #+#             */
/*   Updated: 2017/05/09 14:54:23 by bgrec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "../libft/libft.h"
# include <sys/stat.h>
# include <sys/xattr.h>
# include <sys/types.h>
# include <sys/acl.h>
# include <dirent.h>
# include <errno.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <time.h>

typedef struct	s_metadata
{
	int			s_cnt;
	int			n_cnt;
	int			g_cnt;
	int			l_cnt;
	int			maj_cnt;
	int			min_cnt;
	int			total;
}				t_metadata;

extern char		g_mr_recurse;
extern char		g_a_all;
extern char		g_l_metadata;
extern char		g_t_timesort;
extern char		g_multiple;
extern char		g_printed;
extern char		g_sanitized;
extern char		g_r_reverse;

int				get_entry_count(const char *filename);
int				lexicographic(char *str1, char *str2);
int				timestamp(char *str1, char *str2, char *path);
int				none(void);
int				(*g_sort_criteria)();
int				numsize(int number);
char			**get_entries(const char *filename);
char			*safejoin(char *str1, char *str2);
char			list_perms(char *file, t_metadata *info);
void			insertion_sort(char **entries, int count, const char *fn);
void			insertion_sort_rev(char **entries, int count, const char *fn);
void			failsafe(const char *filename);
void			list_dir(char *filename);
void			sanitize(char **entries, int count);
void			(*g_sort)();
void			prepass_col_size(char *filename, char *entry, t_metadata *info);
void			print_total(int total, char **entries);
void			init_struct(t_metadata *info);
void			padding(int size);
void			other_perm(char mode, struct stat *buffer);
void			print_acl(char *filename);
void			print_maj_min(struct stat *b, t_metadata *info);
void			print_link(char *merged, char *buffer);
DIR				*try_opendir(const char *filename);
#endif
