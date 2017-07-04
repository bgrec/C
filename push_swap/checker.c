/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrec <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 16:49:42 by bgrec             #+#    #+#             */
/*   Updated: 2017/06/21 16:49:44 by bgrec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	set_features(t_stack *stack, char **av)
{
	if (!ft_strcmp(av[1], "-v"))
		stack->features = 1;
	else if (!ft_strcmp(av[1], "-c"))
		stack->features = 2;
	else if (!ft_strcmp(av[1], "-cv") || !ft_strcmp(av[1], "-vc"))
		stack->features = 3;
	else
		return (0);
	return (1);
}

int			main(int ac, char **av)
{
	char	*input;
	t_stack	*stack;

	stack = initstack();
	if (ac == 1)
	{
		ft_putchar('\n');
		return (0);
	}
	if (av[1][0] == '-' && (av[1][1] == 'v' || av[1][1] == 'c'))
		if (set_features(stack, av) && ac--)
			av++;
	if (create_stack(ac, av, &stack))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	stack->b = init_array(stack->size_a);
	while (get_next_line(0, &input) > 0)
	{
		apply_operations(stack, input);
		free(input);
	}
	sort_check(stack) ? ft_putendl("OK") : ft_putendl("KO");
	return (0);
}
