/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:28:12 by kchaouki          #+#    #+#             */
/*   Updated: 2023/02/07 10:08:25 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_swap(t_stack **stack, char *rule_name)
{
	t_stack	*poped1;
	t_stack	*poped2;

	poped1 = NULL;
	poped2 = NULL;
	pop(stack, &poped1);
	pop(stack, &poped2);
	push(stack, &poped1);
	push(stack, &poped2);
	ft_putstr_fd(rule_name, 1);
}
