/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrec <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 16:53:09 by bgrec             #+#    #+#             */
/*   Updated: 2017/06/21 16:53:12 by bgrec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		find_min_max(t_stack *stack)
{
	int	i;
	int	min;
	int	max;

	i = 0;
	min = 0;
	max = 0;
	while (i < stack->size_b)
	{
		if (stack->b[i] > stack->b[max])
			max = i;
		if (stack->b[i] < stack->b[min])
			min = i;
		i++;
	}
	stack->b_max = max;
	stack->b_min = min;
}

int			calc_positions(t_stack *stack, int num)
{
	int	i;
	int	next;

	i = stack->size_b - 1;
	next = stack->b_min;
	if (num > stack->b[stack->b_max] || num < stack->b[stack->b_min])
		return (stack->b_max < (stack->size_b + 1) / 2) ? (stack->b_max) :
		(stack->b_max - stack->size_b);
	while (i >= 0)
	{
		if (stack->b[i] < num && stack->b[i] > stack->b[next])
			next = i;
		i--;
	}
	return (next < (stack->size_b + 1) / 2) ? next : next - stack->size_b;
}

int			ft_abs(int num)
{
	return (num < 0 ? -num : num);
}

void		ft_lstpush(t_list **head, void const *content, int len)
{
	t_list	*current;
	char	*tmp;

	tmp = NULL;
	if (*head == NULL)
	{
		tmp = ft_strdup(content);
		*head = ft_lstnew(tmp, len);
		free(tmp);
	}
	else
	{
		current = *head;
		while (current->next != NULL)
			current = current->next;
		current->next = (t_list*)malloc(sizeof(t_list));
		current->next->content = ft_strdup(content);
		current->next->content_size = len;
		current->next->next = NULL;
	}
}

void		applyop_lstpush(t_stack *stack, char *op, int len)
{
	apply_operations(stack, op);
	ft_lstpush(&stack->ops, op, len);
}
