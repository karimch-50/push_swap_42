/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:28:12 by kchaouki          #+#    #+#             */
/*   Updated: 2023/02/08 19:03:01 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_swap(t_stack **stack, char *rule_name)
{
	t_stack	*poped1;
	t_stack	*poped2;

	if (*stack && (*stack)->next)
	{		
		poped1 = NULL;
		poped2 = NULL;
		pop(stack, &poped1);
		pop(stack, &poped2);
		push(stack, &poped1);
		push(stack, &poped2);
		ft_putstr_fd(rule_name, 1);
	}
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b, char *rule_name)
{
	if (*stack_a && *stack_b)
	{
		ft_swap(stack_a, "");
		ft_swap(stack_b, "");
		ft_putstr_fd(rule_name, 1);
	}
}
