/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrec <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 13:10:26 by bgrec             #+#    #+#             */
/*   Updated: 2017/01/10 13:11:31 by bgrec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*ptr_s;
	size_t		i;

	ptr_s = (const char *)s;
	i = 0;
	if (s == NULL)
		return (NULL);
	while (i < n)
	{
		if (*(ptr_s + i) == (char)c)
			return ((void *)ptr_s + i);
		i++;
	}
	return (NULL);
}
