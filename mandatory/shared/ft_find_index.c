/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:39:42 by kchaouki          #+#    #+#             */
/*   Updated: 2023/02/07 10:07:42 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* find the right position in stack A for a geven position of stack B */
static int	ft_find_winner(t_stack *stack, int pos)
{
	t_stack	*tmp;
	int		winner;

	tmp = stack;
	while (tmp)
	{
		if (tmp->pos > pos)
		{
			winner = tmp->pos;
			break ;
		}
		tmp = tmp->next;
	}
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->pos > pos && tmp->pos < winner)
			winner = tmp->pos;
		tmp = tmp->next;
	}
	return (winner);
}

/* index of the winner in stack A */
int	ft_find_index(t_stack *stack, int pos)
{
	t_stack	*tmp;
	int		winner;	
	int		index;

	winner = ft_find_winner(stack, pos);
	index = 1;
	tmp = stack;
	while (tmp->pos != winner)
	{
		index++;
		tmp = tmp->next;
	}
	return (index);
}
