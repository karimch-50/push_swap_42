/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 07:43:06 by kchaouki          #+#    #+#             */
/*   Updated: 2023/02/07 10:08:40 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_set_pos(t_stack **stack)
{
	t_stack	*tmp1;
	t_stack	*tmp2;
	int		pos;

	tmp1 = *stack;
	while (tmp1)
	{
		pos = 0;
		tmp2 = *stack;
		while (tmp2)
		{
			if (tmp1->num > tmp2->num)
				pos++;
			tmp2 = tmp2->next;
		}
		tmp1->pos = pos;
		tmp1 = tmp1->next;
	}
}
