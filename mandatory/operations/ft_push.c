/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:18:16 by kchaouki          #+#    #+#             */
/*   Updated: 2023/02/07 10:08:19 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	ft_push(t_stack **stack1, t_stack **stack2)
{
	t_stack	*poped;

	if (*stack1)
	{
		poped = NULL;
		pop(stack1, &poped);
		push(stack2, &poped);
	}
}

void	ft_p(t_stack **stack_a, t_stack **stack_b, char a_b, int shee)
{
	if (a_b == 'a')
	{
		ft_push(stack_b, stack_a);
		if (shee == 1)
			ft_putstr_fd("pa\n", 1);
	}
	if (a_b == 'b')
	{
		ft_push(stack_a, stack_b);
		if (shee == 1)
			ft_putstr_fd("pb\n", 1);
	}
}
