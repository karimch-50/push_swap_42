/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 09:02:47 by kchaouki          #+#    #+#             */
/*   Updated: 2023/02/07 10:07:52 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* find the index of given position in the stack */
int	ft_pos_index(t_stack *stack, int pos)
{
	t_stack	*tmp;
	int		index;

	tmp = stack;
	index = 0;
	while (tmp->pos != pos)
	{
		index++;
		tmp = tmp->next;
	}
	return (index);
}
