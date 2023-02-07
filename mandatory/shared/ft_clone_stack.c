/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clone_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:01:55 by kchaouki          #+#    #+#             */
/*   Updated: 2023/02/07 10:07:39 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* make a copy of a given stack */
t_stack	*ft_clone_stack(t_stack **stack)
{
	t_stack	*cloned;
	t_stack	*tmp;

	cloned = NULL;
	tmp = *stack;
	while (tmp)
	{
		ft_add_to_stack(&cloned, tmp->num, tmp->pos);
		tmp = tmp->next;
	}
	return (cloned);
}
