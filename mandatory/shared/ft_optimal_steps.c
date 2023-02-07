/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimal_steps.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:49:07 by kchaouki          #+#    #+#             */
/*   Updated: 2023/02/07 10:07:50 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* count how many steps it's gonna take to put
a given position on top of stack_b */
static int	ft_stack_b_steps(t_stack *stack, int pos)
{
	int		stack_size;
	int		index;

	stack_size = ft_stack_size(stack);
	index = ft_pos_index(stack, pos);
	if (index <= (stack_size / 2))
		return (index);
	return (index - stack_size);
}

/* count how many steps it's gonna take 
to put a given position on top of stack_a */
static int	ft_stack_a_steps(t_stack *stack, int pos)
{
	int	stack_size;
	int	index;

	index = ft_find_index(stack, pos);
	stack_size = ft_stack_size(stack);
	if (index <= (stack_size / 2))
		return (index - 1);
	return ((index - 1) - stack_size);
}

int	ft_optimal(t_stack *stack_a, t_stack *stack_b, t_operations *op)
{
	t_stack			*tmp_stack_b;
	t_operations	operations;
	int				total;
	int				old_total;
	int				optimal;

	tmp_stack_b = stack_b;
	old_total = INT_MAX;
	optimal = tmp_stack_b->pos;
	while (tmp_stack_b)
	{
		total = ft_calculator(ft_stack_a_steps(stack_a, tmp_stack_b->pos), \
			ft_stack_b_steps(stack_b, tmp_stack_b->pos), &operations);
		if (total < old_total)
		{
			ft_set_op(op, &operations);
			old_total = total;
			optimal = tmp_stack_b->pos;
		}
		tmp_stack_b = tmp_stack_b->next;
	}
	return (optimal);
}
