/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 10:57:16 by kchaouki          #+#    #+#             */
/*   Updated: 2023/02/07 10:08:14 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_set_op(t_operations *old, t_operations *new)
{
	(*old).ra = (*new).ra;
	(*old).rra = (*new).rra;
	(*old).rb = (*new).rb;
	(*old).rrb = (*new).rrb;
	(*old).rr = (*new).rr;
	(*old).rrr = (*new).rrr;
}

void	ft_initial_op_struct(t_operations *op)
{
	(*op).ra = 0;
	(*op).rra = 0;
	(*op).rb = 0;
	(*op).rrb = 0;
	(*op).rr = 0;
	(*op).rrr = 0;
}
