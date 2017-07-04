/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrec <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 15:28:20 by bgrec             #+#    #+#             */
/*   Updated: 2017/01/21 12:59:06 by bgrec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 4096
# include "libft/libft.h"
# include <unistd.h>

typedef struct	s_get_next_line
{
	int		fd;
	char	*buff;
	int		size;
	int		i;
	int		new_ln;
}				t_data;

int				get_next_line(int const fd, char **line);
#endif
