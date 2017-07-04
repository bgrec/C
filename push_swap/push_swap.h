/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrec <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 16:50:35 by bgrec             #+#    #+#             */
/*   Updated: 2017/06/21 16:52:09 by bgrec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# define RED		"\x1b[31m"
# define GREEN	"\x1b[32m"
# define RESET	"\x1b[0m"

typedef struct	s_stack
{
	int		features;
	t_list	*ops;
	int		*a;
	int		*b;
	int		size_a;
	int		size_b;
	int		b_max;
	int		b_min;
	int		t_rots;
	int		a_rots;
	int		b_rots;
}				t_stack;

void			free_split(char ***split);
void			prints(t_stack *stack, char *input);
void			sort_three(t_stack *stack);
void			op_lst(t_stack *stack, char *op);
int				create_stack(int ac, char **av, t_stack **st);
int				list_len(t_list *ls);
int				*moveto_array(t_list *stack, int stack_len);
void			free_stack(t_stack *stack);
int				*init_array(int size);
t_stack			*initstack(void);
void			reset_stack(t_stack *stack);
int				sort_check(t_stack *stack);
void			sort_large(t_stack *stack);
void			calc_rotation(t_stack *stack);
void			sort_small(t_stack *stack);
void			apply_operations(t_stack *stack, char *input);
int				ps_swap(t_stack *stack, char option);
int				ps_push(t_stack *stack, char option);
int				ps_rotate(t_stack *stack, char option);
int				ps_reverse_rotate(t_stack *stack, char option);
void			find_min_max(t_stack *stack);
int				calc_positions(t_stack *stack, int num);
int				ft_abs(int num);
void			ft_lstpush(t_list **head, void const *content, int len);
void			display_stack(t_stack *stack, int *a_copy);
void			ft_lstfree(t_list *head);
void			ft_lstprint(t_list *head);
int				*ft_intdup(int *array, int size);
void			print_stacks(t_stack *stack);
#endif
