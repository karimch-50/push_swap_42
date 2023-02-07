/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 09:36:51 by kchaouki          #+#    #+#             */
/*   Updated: 2023/02/07 10:08:28 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push(t_stack **stack, t_stack **to_push)
{
	if (!(*stack))
	{
		(*stack) = (*to_push);
		return ;
	}
	(*to_push)->next = (*stack);
	(*stack) = (*to_push);
	(*to_push) = NULL;
}

void	pop(t_stack **stack, t_stack **poped)
{
	t_stack	*tmp;

	tmp = (*stack)->next;
	(*poped) = (*stack);
	(*stack) = tmp;
	(*poped)->next = NULL;
}
