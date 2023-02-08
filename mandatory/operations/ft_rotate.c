/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:29:09 by kchaouki          #+#    #+#             */
/*   Updated: 2023/02/08 18:58:32 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_rotate(t_stack **stack, char *rule_name)
{
	t_stack	*poped_to_down;
	t_stack	*tmp_stack;
	t_stack	*poped;

	if (*stack && (*stack)->next)
	{
		poped_to_down = NULL;
		tmp_stack = NULL;
		poped = NULL;
		pop(stack, &poped_to_down);
		while ((*stack))
		{
			pop(stack, &poped);
			push(&tmp_stack, &poped);
		}
		push(stack, &poped_to_down);
		while (tmp_stack)
		{
			pop(&tmp_stack, &poped);
			push(stack, &poped);
		}
		ft_putstr_fd(rule_name, 1);
	}
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b, char *rule_name)
{
	if (*stack_a && *stack_b)
	{
		ft_rotate(stack_a, NULL);
		ft_rotate(stack_b, NULL);
		ft_putstr_fd(rule_name, 1);
	}
}
