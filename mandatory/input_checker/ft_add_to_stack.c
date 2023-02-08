/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_to_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:30:44 by kchaouki          #+#    #+#             */
/*   Updated: 2023/02/08 19:46:04 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_add_to_stack(t_stack **list, int content, int pos)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
	{
		ft_free_stack(list);
		(*list) = NULL;
		return ;
	}
	new->num = content;
	new->pos = pos;
	new->tag = 0;
	new->next = (*list);
	(*list) = new;
}
