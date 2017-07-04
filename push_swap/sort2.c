/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrec <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 16:50:58 by bgrec             #+#    #+#             */
/*   Updated: 2017/06/21 16:50:59 by bgrec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rot_possible(t_stack *stack)
{
	int		i;
	int		ret;

	i = -1;
	ret = 0;
	while (++i < stack->size_a)
	{
		if (sort_check(stack))
			ret = 1;
		apply_operations(stack, "ra");
	}
	return (ret);
}

static int	calc_pivot(t_stack *stack)
{
	int		i;
	int		pivot;

	i = 0;
	pivot = -1;
	while (i < stack->size_a)
	{
		if (sort_check(stack))
			pivot = i;
		apply_operations(stack, "ra");
		i++;
	}
	return (pivot);
}

static void	rotate_a(t_stack *stack)
{
	int		pivot;

	pivot = calc_pivot(stack);
	if (pivot < (stack->size_a + 1) / 2 && pivot != -1)
	{
		while (pivot > 0)
		{
			apply_operations(stack, "ra");
			ft_lstpush(&stack->ops, "ra", 3);
			pivot--;
		}
	}
	else if (pivot >= (stack->size_a + 1) / 2)
	{
		while (pivot < stack->size_a)
		{
			apply_operations(stack, "rra");
			ft_lstpush(&stack->ops, "rra", 3);
		}
	}
}

static void	push_min(t_stack *stack)
{
	int		i;
	int		min;

	i = -1;
	min = 0;
	while (++i < stack->size_a)
		if (stack->a[i] < stack->a[min])
			min = i;
	min = (min <= (stack->size_a + 1) / 2) ? min : min - stack->size_a;
	while (min > 0)
	{
		apply_operations(stack, "ra");
		ft_lstpush(&stack->ops, "ra", 2);
		min--;
	}
	while (min < 0)
	{
		apply_operations(stack, "rra");
		ft_lstpush(&stack->ops, "pb", 2);
		min++;
	}
	apply_operations(stack, "pb");
	ft_lstpush(&stack->ops, "pb", 2);
}

void		sort_small(t_stack *stack)
{
	if (sort_check(stack))
		return ;
	if (stack->size_a == 2)
	{
		apply_operations(stack, "ra");
		ft_lstpush(&stack->ops, "ra", 2);
		return ;
	}
	if (stack->size_a == 3)
	{
		sort_three(stack);
		return ;
	}
	if (rot_possible(stack))
		rotate_a(stack);
	else
	{
		while (stack->size_a > 1)
			push_min(stack);
		while (stack->size_b)
		{
			apply_operations(stack, "pa");
			ft_lstpush(&stack->ops, "pa", 2);
		}
	}
}
