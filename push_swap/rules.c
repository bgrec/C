/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrec <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 16:50:42 by bgrec             #+#    #+#             */
/*   Updated: 2017/06/21 16:50:44 by bgrec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ps_swap(t_stack *stack, char option)
{
	int	temp;

	if ((option == 'a' || option == 'c') && stack->size_a > 1)
	{
		temp = stack->a[0];
		stack->a[0] = stack->a[1];
		stack->a[1] = temp;
	}
	if ((option == 'b' || option == 'c') && stack->size_b > 1)
	{
		temp = stack->b[0];
		stack->b[0] = stack->b[1];
		stack->b[1] = temp;
	}
	return (1);
}

int		ps_push(t_stack *stack, char option)
{
	int	temp;

	if (option == 'a' && stack->size_b > 0)
	{
		temp = stack->b[0];
		stack->b[0] = 0;
		ps_rotate(stack, 'b');
		stack->size_a++;
		stack->size_b--;
		ps_reverse_rotate(stack, 'a');
		stack->a[0] = temp;
	}
	if (option == 'b' && stack->size_a > 0)
	{
		temp = stack->a[0];
		stack->a[0] = 0;
		ps_rotate(stack, 'a');
		stack->size_b++;
		stack->size_a--;
		ps_reverse_rotate(stack, 'b');
		stack->b[0] = temp;
	}
	return (1);
}

int		ps_rotate(t_stack *stack, char option)
{
	int	temp;
	int	i;

	if (option == 'a' || option == 'c')
	{
		temp = stack->a[0];
		i = -1;
		while (++i < stack->size_a - 1)
			stack->a[i] = stack->a[i + 1];
		stack->a[stack->size_a - 1] = temp;
	}
	if (option == 'b' || option == 'c')
	{
		temp = stack->b[0];
		i = -1;
		while (++i < stack->size_b - 1)
			stack->b[i] = stack->b[i + 1];
		stack->b[stack->size_b - 1] = temp;
	}
	return (1);
}

int		ps_reverse_rotate(t_stack *stack, char option)
{
	int	temp;
	int	i;

	if (option == 'a' || option == 'c')
	{
		temp = stack->a[stack->size_a - 1];
		i = stack->size_a;
		while (i-- > 0)
			stack->a[i] = stack->a[i - 1];
		stack->a[0] = temp;
	}
	if (option == 'b' || option == 'c')
	{
		temp = stack->b[stack->size_b - 1];
		i = stack->size_b;
		while (i-- > 0)
			stack->b[i] = stack->b[i - 1];
		stack->b[0] = temp;
	}
	return (1);
}

void	apply_operations(t_stack *stack, char *input)
{
	if (!ft_strcmp(input, "sa"))
		ps_swap(stack, 'a');
	else if (!ft_strcmp(input, "sb"))
		ps_swap(stack, 'b');
	else if (!ft_strcmp(input, "ss"))
		ps_swap(stack, 'c');
	else if (!ft_strcmp(input, "pa"))
		ps_push(stack, 'a');
	else if (!ft_strcmp(input, "pb"))
		ps_push(stack, 'b');
	else if (!ft_strcmp(input, "pp"))
		ps_push(stack, 'c');
	else if (!ft_strcmp(input, "ra"))
		ps_rotate(stack, 'a');
	else if (!ft_strcmp(input, "rb"))
		ps_rotate(stack, 'b');
	else if (!ft_strcmp(input, "rr"))
		ps_rotate(stack, 'c');
	else if (!ft_strcmp(input, "rra"))
		ps_reverse_rotate(stack, 'a');
	else if (!ft_strcmp(input, "rrb"))
		ps_reverse_rotate(stack, 'b');
	else if (!ft_strcmp(input, "rrr"))
		ps_reverse_rotate(stack, 'c');
	prints(stack, input);
}
