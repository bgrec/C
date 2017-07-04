/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrec <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 16:50:50 by bgrec             #+#    #+#             */
/*   Updated: 2017/06/21 16:50:51 by bgrec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				sort_check(t_stack *stack)
{
	int		i;

	if (stack->size_b != 0)
		return (0);
	i = -1;
	while (++i < stack->size_a - 1)
	{
		if (stack->a[i] > stack->a[i + 1])
			return (0);
	}
	return (1);
}

static void		rotate_indiv(t_stack *stack)
{
	while (stack->a_rots > 0)
	{
		apply_operations(stack, "ra");
		ft_lstpush(&stack->ops, "ra", 2);
		stack->a_rots--;
	}
	while (stack->a_rots < 0)
	{
		apply_operations(stack, "rra");
		ft_lstpush(&stack->ops, "rra", 3);
		stack->a_rots++;
	}
	while (stack->b_rots > 0)
	{
		apply_operations(stack, "rb");
		ft_lstpush(&stack->ops, "rb", 2);
		stack->b_rots--;
	}
	while (stack->b_rots < 0)
	{
		apply_operations(stack, "rrb");
		ft_lstpush(&stack->ops, "rrb", 3);
		stack->b_rots++;
	}
	reset_stack(stack);
}

static void		rotate_both(t_stack *stack)
{
	while (stack->a_rots > 0 && stack->b_rots > 0)
	{
		apply_operations(stack, "rr");
		ft_lstpush(&stack->ops, "rr", 2);
		stack->a_rots--;
		stack->b_rots--;
	}
	while (stack->a_rots < 0 && stack->b_rots < 0)
	{
		apply_operations(stack, "rrr");
		ft_lstpush(&stack->ops, "rrr", 3);
		stack->a_rots++;
		stack->b_rots++;
	}
	rotate_indiv(stack);
}

static void		rotate_b(t_stack *stack)
{
	int			rots;

	find_min_max(stack);
	rots = (stack->b_max < (stack->size_b + 1) / 2) ?
		stack->b_max : stack->b_max - stack->size_b;
	while (rots > 0)
	{
		apply_operations(stack, "rb");
		ft_lstpush(&stack->ops, "rb", 2);
		rots--;
	}
	while (rots < 0)
	{
		apply_operations(stack, "rrb");
		ft_lstpush(&stack->ops, "rrb", 2);
		rots++;
	}
}

void			sort_large(t_stack *stack)
{
	if (sort_check(stack))
		return ;
	apply_operations(stack, "pb");
	stack->ops = ft_lstnew("pb", 2);
	while (stack->size_a > 0)
	{
		calc_rotation(stack);
		rotate_both(stack);
		apply_operations(stack, "pb");
		ft_lstpush(&stack->ops, "pb", 2);
		reset_stack(stack);
	}
	rotate_b(stack);
	while (stack->size_b > 0)
	{
		apply_operations(stack, "pa");
		ft_lstpush(&stack->ops, "pa", 2);
	}
}
