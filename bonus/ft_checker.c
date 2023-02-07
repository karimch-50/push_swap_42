/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 09:03:43 by kchaouki          #+#    #+#             */
/*   Updated: 2023/02/07 10:04:47 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

static void	conditions_1(char *line, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strncmp(line, "sa\n", 4) == 0)
		ft_swap(stack_a, "");
	if (ft_strncmp(line, "sb\n", 3) == 0)
		ft_swap(stack_b, "");
	if (ft_strncmp(line, "ra\n", 3) == 0)
		ft_rotate(stack_a, "");
	if (ft_strncmp(line, "rb\n", 3) == 0)
		ft_rotate(stack_b, "");
	if (ft_strncmp(line, "rra\n", 4) == 0)
		ft_rev_rotate(stack_a, "");
	if (ft_strncmp(line, "rrb\n", 4) == 0)
		ft_rev_rotate(stack_b, "");
	if (ft_strncmp(line, "pa\n", 4) == 0)
		ft_p(stack_a, stack_b, 'a', 0);
	if (ft_strncmp(line, "pb\n", 4) == 0)
		ft_p(stack_a, stack_b, 'b', 0);
}

static void	conditions_2(char *line, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strncmp(line, "ss\n", 3) == 0)
	{
		ft_swap(stack_a, "");
		ft_swap(stack_b, "");
	}
	if (ft_strncmp(line, "rr\n", 3) == 0)
	{
		ft_rotate(stack_a, "");
		ft_rotate(stack_b, "");
	}
	if (ft_strncmp(line, "rrr\n", 4) == 0)
	{
		ft_rev_rotate(stack_a, "");
		ft_rev_rotate(stack_b, "");
	}
}

static void	conditions(char *line, t_stack **stack_a, t_stack **stack_b)
{
	conditions_1(line, stack_a, stack_b);
	conditions_2(line, stack_a, stack_b);
}

void	ft_checker(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;

	stack_b = NULL;
	stack_a = ft_resolver(argc, argv);
	if (stack_a)
	{
		line = get_next_line(0);
		while (line)
		{
			conditions(line, &stack_a, &stack_b);
			free(line);
			line = get_next_line(0);
		}
		if (ft_stack_is_sorted(stack_a))
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO\n", 1);
	}
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
}
