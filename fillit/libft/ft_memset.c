/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrec <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 13:20:56 by bgrec             #+#    #+#             */
/*   Updated: 2017/01/10 13:23:24 by bgrec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*b_char;

	if (b == NULL || len <= 0)
		return (b);
	b_char = (unsigned char*)b;
	while (len > 0)
	{
		*b_char = (unsigned char)c;
		b_char++;
		len--;
	}
	return (b);
}
