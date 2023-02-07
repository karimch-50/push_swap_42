/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:06:55 by kchaouki          #+#    #+#             */
/*   Updated: 2023/02/07 10:07:37 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* the absolute value of a given number*/
static int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

/*count the total and common instruction for rotate*/
static int	ft_rr_case(int stack_a_op, int stack_b_op, t_operations *op)
{
	int	count;

	count = 0;
	if (stack_a_op > stack_b_op)
	{
		(*op).rr = stack_b_op;
		(*op).ra = stack_a_op - stack_b_op;
		count = stack_a_op;
	}
	else
	{
		(*op).rr = stack_a_op;
		(*op).rb = stack_b_op - stack_a_op;
		count = stack_b_op;
	}
	return (count);
}

/*count the total and common instruction for rev rotate*/
static int	ft_rrr_case(int stack_a_op, int stack_b_op, t_operations *op)
{
	int	count;

	count = 0;
	if (stack_a_op < stack_b_op)
	{
		(*op).rrr = ft_abs(stack_b_op);
		(*op).rra = ft_abs(stack_a_op) - ft_abs(stack_b_op);
		count = ft_abs(stack_a_op);
	}
	else
	{
		(*op).rrr = ft_abs(stack_a_op);
		(*op).rrb = ft_abs(stack_b_op) - ft_abs(stack_a_op);
		count = ft_abs(stack_b_op);
	}
	return (count);
}

/*count the totatl and the number of each instruction*/
static int	ft_rx_case(int stack_a_op, int stack_b_op, t_operations *op)
{
	int	count;

	count = 0;
	if (stack_a_op > 0)
	{
		(*op).ra = stack_a_op;
		count += stack_a_op;
	}
	else if (stack_a_op < 0)
	{
		(*op).rra = ft_abs(stack_a_op);
		count += ft_abs(stack_a_op);
	}
	if (stack_b_op > 0)
	{
		(*op).rb = stack_b_op;
		count += stack_b_op;
	}
	else if (stack_b_op < 0)
	{
		(*op).rrb = ft_abs(stack_b_op);
		count += ft_abs(stack_b_op);
	}
	return (count);
}

int	ft_calculator(int stack_a_op, int stack_b_op, t_operations *op)
{
	int	counter;

	counter = 0;
	ft_initial_op_struct(op);
	if (stack_a_op > 0 && stack_b_op > 0)
		counter = ft_rr_case(stack_a_op, stack_b_op, op);
	else if (stack_a_op < 0 && stack_b_op < 0)
		counter = ft_rrr_case(stack_a_op, stack_b_op, op);
	else
		counter = ft_rx_case(stack_a_op, stack_b_op, op);
	return (counter + 1);
}
