/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_need_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:41:52 by kchaouki          #+#    #+#             */
/*   Updated: 2023/02/07 10:07:48 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	ft_count_valid_tags(char *tags)
{
	int	count;

	count = 0;
	while (*tags)
	{
		if (*tags == '1')
			count++;
		tags++;
	}
	return (count);
}

int	ft_need_swap(t_stack *stack)
{
	t_stack	*tmp;
	char	*tags1;
	char	*tags2;
	int		*pos1;
	int		*pos2;

	tmp = ft_clone_stack(&stack);
	ft_swap(&tmp, "");
	pos1 = ft_pos_to_arr(tmp);
	pos2 = ft_pos_to_arr(stack);
	tags1 = ft_best_marker(tmp, pos1, ft_stack_size(tmp));
	tags2 = ft_best_marker(stack, pos2, ft_stack_size(stack));
	free(pos1);
	free(pos2);
	if (ft_count_valid_tags(tags1) > ft_count_valid_tags(tags2))
		return (free(tags1), free(tags2), ft_free_stack(&tmp), 1);
	return (free(tags1), free(tags2), ft_free_stack(&tmp), 0);
}
