/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_need_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 11:41:12 by kchaouki          #+#    #+#             */
/*   Updated: 2023/02/07 10:07:46 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_need_rotate(t_stack *stack, int pos)
{
	int		size;
	int		index;

	size = ft_stack_size(stack);
	index = ft_find_index(stack, pos);
	if (index <= (size / 2))
		return (1);
	return (0);
}
