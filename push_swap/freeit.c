/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrec <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 16:49:59 by bgrec             #+#    #+#             */
/*   Updated: 2017/06/21 16:50:00 by bgrec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		calc_rotation(t_stack *stack)
{
	int		i;
	int		a;
	int		b;
	int		rots;
	int		flag;

	i = -1;
	flag = 0;
	while (++i < stack->size_a)
	{
		find_min_max(stack);
		a = (i < (stack->size_a + 1) / 2) ? (i) : (i - stack->size_a);
		b = calc_positions(stack, stack->a[i]);
		if (a * b < 0)
			rots = 1 + ft_abs(a) + ft_abs(b);
		else
			rots = (ft_abs(a) > ft_abs(b)) ? ft_abs(a) + 1 : ft_abs(b) + 1;
		if (rots < stack->t_rots || flag == 0)
		{
			flag = 1;
			stack->t_rots = rots;
			stack->a_rots = a;
			stack->b_rots = b;
		}
	}
}

void		free_split(char ***split)
{
	int	i;

	i = 0;
	while ((*split)[i])
	{
		free((*split)[i]);
		i++;
	}
	free(*split);
	*split = NULL;
}

void		prints(t_stack *stack, char *input)
{
	if (stack->features == 1 || stack->features == 3)
	{
		ft_putstr("\n\noperation: ");
		ft_putstr(input);
		ft_putstr("\n");
		print_stacks(stack);
	}
}

void		op_lst(t_stack *stack, char *op)
{
	char	*tmp;

	tmp = ft_strdup(op);
	apply_operations(stack, op);
	ft_lstpush(&stack->ops, tmp, ft_strlen(op));
	free(tmp);
}

void		sort_three(t_stack *stack)
{
	if (stack->a[0] > stack->a[2])
	{
		op_lst(stack, "ra");
		if (sort_check(stack))
			return ;
		op_lst(stack, "sa");
	}
	if (stack->a[0] > stack->a[1])
	{
		op_lst(stack, "sa");
		if (sort_check(stack))
			return ;
	}
	if (stack->a[1] > stack->a[2])
	{
		op_lst(stack, "rra");
		if (sort_check(stack))
			return ;
		op_lst(stack, "sa");
	}
}
