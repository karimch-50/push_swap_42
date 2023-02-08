/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:51:17 by kchaouki          #+#    #+#             */
/*   Updated: 2023/02/08 18:59:32 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_rev_rotate(t_stack **stack, char *rule_name)
{
	t_stack	*poped_to_up;	
	t_stack	*tmp_stack;	
	t_stack	*poped;

	if (*stack && (*stack)->next)
	{	
		poped_to_up = NULL;
		tmp_stack = NULL;
		poped = NULL;
		while ((*stack)->next)
		{
			pop(stack, &poped);
			push(&tmp_stack, &poped);
		}
		pop(stack, &poped_to_up);
		while (tmp_stack)
		{
			pop(&tmp_stack, &poped);
			push(stack, &poped);
		}
		push(stack, &poped_to_up);
		ft_putstr_fd(rule_name, 1);
	}
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b, char *rule_name)
{
	if (*stack_a && *stack_b)
	{
		ft_rev_rotate(stack_a, "");
		ft_rev_rotate(stack_b, "");
		ft_putstr_fd(rule_name, 1);
	}
}
