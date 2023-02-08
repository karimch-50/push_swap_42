/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clone_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:01:55 by kchaouki          #+#    #+#             */
/*   Updated: 2023/02/08 20:33:16 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* make a copy of a given stack */
t_stack	*ft_clone_stack(t_stack **stack)
{
	t_stack	*cloned;
	t_stack	*tmp;
	int		i;
	int		j;

	i = 0;
	cloned = NULL;
	tmp = *stack;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	while (i)
	{
		tmp = *stack;
		j = 0;
		while (j++ < i - 1)
			tmp = tmp->next;
		ft_add_to_stack(&cloned, tmp->num, tmp->pos);
		i--;
	}
	return (cloned);
}
