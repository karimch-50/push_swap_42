/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos_to_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:27:01 by kchaouki          #+#    #+#             */
/*   Updated: 2023/02/07 10:07:54 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* put all the positions of the struct inside an array of int */
int	*ft_pos_to_arr(t_stack *stack)
{
	int		*output;
	int		i;

	output = malloc(ft_stack_size(stack) * sizeof(int));
	if (!output)
		return (0);
	i = 0;
	while (stack)
	{
		output[i++] = stack->pos;
		stack = stack->next;
	}
	return (output);
}
