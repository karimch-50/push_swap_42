/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_operation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 11:06:15 by kchaouki          #+#    #+#             */
/*   Updated: 2023/02/08 19:04:34 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_apply_rr(t_stack **stack_a, t_stack **stack_b, int *rr)
{
	while ((*rr))
	{
		ft_rr(stack_a, stack_b, "rr\n");
		(*rr)--;
	}
}

void	ft_apply_rrr(t_stack **stack_a, t_stack **stack_b, int *rrr)
{
	while ((*rrr))
	{
		ft_rrr(stack_a, stack_b, "rrr\n");
		(*rrr)--;
	}
}

void	ft_apply_rx(t_stack **stack_a, t_stack **stack_b, int *ra, int *rb)
{
	if ((*ra) > 0)
	{
		while ((*ra))
		{
			ft_rotate(stack_a, "ra\n");
			(*ra)--;
		}
	}
	if ((*rb) > 0)
	{
		while ((*rb))
		{
			ft_rotate(stack_b, "rb\n");
			(*rb)--;
		}
	}
}

void	ft_apply_rrx(t_stack **stack_a, t_stack **stack_b, int *rra, int *rrb)
{
	if ((*rra) > 0)
	{
		while ((*rra))
		{
			ft_rev_rotate(stack_a, "rra\n");
			(*rra)--;
		}
	}
	if ((*rrb) > 0)
	{
		while ((*rrb))
		{
			ft_rev_rotate(stack_b, "rrb\n");
			(*rrb)--;
		}
	}
}
