/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 10:29:19 by kchaouki          #+#    #+#             */
/*   Updated: 2023/02/07 10:07:04 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* check if the tag inside struct has a value of 0 */
static	int	ft_has_0_tag(t_stack *stack)
{
	while (stack)
	{
		if (stack->tag == 0)
			return (1);
		stack = stack->next;
	}
	return (0);
}

/* sort stack A */
static void	ft_sort_1(t_stack **stack_a, t_stack **stack_b)
{
	ft_tags_to_stack(stack_a);
	while (!ft_stack_is_sorted((*stack_a)) && ft_has_0_tag((*stack_a)))
	{
		if (ft_need_swap((*stack_a)))
		{
			ft_swap(stack_a, "sa\n");
			ft_tags_to_stack(stack_a);
		}
		else if ((*stack_a)->tag == 0)
			ft_p(stack_a, stack_b, 'b', 1);
		else
			ft_rotate(stack_a, "ra\n");
	}
}

/* check and find the optimal number to push to 
it's right position in stack A */
static void	ft_sort_2(t_stack **stack_a, t_stack **stack_b)
{
	t_operations	op;
	int				optimal;

	optimal = 0;
	while ((*stack_b))
	{
		optimal = ft_optimal((*stack_a), (*stack_b), &op);
		if (op.rrr > 0)
			ft_apply_rrr(stack_a, stack_b, &op.rrr);
		if (op.rr > 0)
			ft_apply_rr(stack_a, stack_b, &op.rr);
		if (op.ra > 0 || op.rb > 0)
			ft_apply_rx(stack_a, stack_b, &op.ra, &op.rb);
		if (op.rra > 0 || op.rrb > 0)
			ft_apply_rrx(stack_a, stack_b, &op.rra, &op.rrb);
		if (ft_pos_index((*stack_b), optimal) == 0)
			ft_p(stack_a, stack_b, 'a', 1);
	}
}

/* put the lowest number with position 0 in top of stack A */
static void	ft_final_sort(t_stack **stack)
{
	int	index;
	int	size;

	index = ft_pos_index((*stack), 0);
	size = ft_stack_size((*stack));
	if ((*stack)->pos == 0)
		return ;
	if (index <= (size / 2))
	{
		while ((*stack)->pos != 0)
			ft_rotate(stack, "ra\n");
	}
	else
	{
		while ((*stack)->pos != 0)
			ft_rev_rotate(stack, "rra\n");
	}
}

void	push_swap(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = ft_resolver(argc, argv);
	stack_b = NULL;
	if (stack_a && ft_stack_size(stack_a) > 1)
	{
		ft_sort_1(&stack_a, &stack_b);
		ft_sort_2(&stack_a, &stack_b);
		ft_final_sort(&stack_a);
		ft_free_stack(&stack_a);
		ft_free_stack(&stack_b);
	}
}
