/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrec <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 15:33:52 by bgrec             #+#    #+#             */
/*   Updated: 2017/01/21 13:10:21 by bgrec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		ft_delete_data(t_list **list, int fd, char **str)
{
	t_data	*data;
	t_list	*list_ptr;
	t_list	**temp_list;

	temp_list = list;
	while (*temp_list)
	{
		data = (t_data *)((*temp_list)->content);
		if (data->fd == fd)
			break ;
		*temp_list = ((*temp_list)->next);
	}
	if (*temp_list)
	{
		list_ptr = (*temp_list)->next;
		ft_strdel(&(data->buff));
		ft_memdel((void **)&data);
		ft_memdel((void **)temp_list);
		*temp_list = list_ptr;
	}
	ft_strdel(str);
}

int			ft_read_buff(t_data *data, t_list **list, char **temp,
		char **line)
{
	if (data->i == data->size)
	{
		data->size = read(data->fd, data->buff, BUFF_SIZE);
		if (data->size == -1)
		{
			ft_delete_data(list, data->fd, temp);
			return (-1);
		}
		data->i = 0;
		if (data->size == 0)
		{
			if (data->new_ln == 0)
			{
				*line = *temp;
				return (1);
			}
		}
	}
	return (0);
}

t_data		*ft_put_data(t_list **list, int fd)
{
	t_data	*data;
	t_list	*temp_list;

	temp_list = *list;
	while (temp_list)
	{
		data = (t_data *)(temp_list->content);
		if (data->fd == fd)
			return (data);
		temp_list = temp_list->next;
	}
	data = (t_data *)ft_memalloc(sizeof(t_data));
	data->size = BUFF_SIZE;
	data->i = BUFF_SIZE;
	data->fd = fd;
	data->new_ln = 1;
	data->buff = ft_strnew(BUFF_SIZE);
	temp_list = ft_lstnew(data, sizeof(t_data));
	ft_memdel((void **)&data);
	ft_lstadd(list, temp_list);
	return ((t_data *)(temp_list->content));
}

char		*ft_append_newline(t_data *data)
{
	int	i;

	i = 0;
	data->new_ln = 0;
	while (data->i + i < data->size)
	{
		if (data->buff[data->i + i] == '\n')
		{
			data->new_ln = 1;
			i++;
			break ;
		}
		i++;
	}
	data->i += i;
	return (ft_strsub(data->buff, data->i - i, i - data->new_ln));
}

int			get_next_line(int const fd, char **line)
{
	static t_list	*list;
	t_data			*data;
	char			*temp;
	int				r_value;

	if (fd < 0 || line == NULL)
		return (-1);
	data = ft_put_data(&list, fd);
	temp = ft_strnew(0);
	while (data->size > 0)
	{
		if ((r_value = ft_read_buff(data, &list, &temp, line)) != 0)
			return (r_value);
		while (data->i < data->size)
		{
			temp = ft_strmerge(temp, ft_append_newline(data));
			if (data->new_ln)
			{
				*line = temp;
				return (1);
			}
		}
	}
	ft_delete_data(&list, fd, &temp);
	return (0);
}
