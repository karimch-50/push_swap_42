/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:14:00 by kchaouki          #+#    #+#             */
/*   Updated: 2023/02/09 12:09:08 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* check if ther is any characters different from (digit,space,+,-). */
static int	ft_check_one(char *combined_args)
{
	int	i;

	i = 0;
	if (!combined_args)
		return (ft_putstr_fd("Error\n", 2), 0);
	while (combined_args[i])
	{
		if (!ft_isdigit(combined_args[i]) && !ft_isspace(combined_args[i])
			&& combined_args[i] != '+' && combined_args[i] != '-')
			return (ft_putstr_fd("Error\n", 2), 0);
		i++;
	}
	return (1);
}

/* check if there is more then one (+ or -) or after a degit */
static int	ft_check_three(char	*str)
{
	int	j;

	j = 0;
	if (str[j] == '+' || str[j] == '-')
		j++;
	if (str[j] == '\0')
		return (0);
	while (str[j])
	{
		if (!ft_isdigit(str[j]))
			return (0);
		j++;
	}
	return (1);
}

/* check if args are (> or <) than an integer and/or there are duplicates. */
static int	ft_check_two(char **split)
{
	int	i;
	int	j;

	i = 0;
	while (split[i] != 0)
	{	
		if (ft_strlen(split[i]) > 11 || (ft_atoi(split[i]) < INT_MIN
				|| ft_atoi(split[i]) > INT_MAX) || !ft_check_three(split[i]))
			return (ft_putstr_fd("Error\n", 2), 0);
		j = i + 1;
		while (split[j])
		{
			if (ft_atoi(split[i]) == ft_atoi(split[j]))
				return (ft_putstr_fd("Error\n", 2), 0);
			j++;
		}
		i++;
	}
	return (1);
}

static t_stack	*ft_args_checker(int argc, char **argv)
{
	char	*joined_args;
	char	**split;
	t_stack	*stack;
	int		i;

	joined_args = ((stack = NULL), (i = 1), NULL);
	while (i < argc)
	{
		joined_args = ft_join_args(joined_args, argv[i++]);
		if (!joined_args)
			break ;
	}
	if (!ft_check_one(joined_args))
		return ((free(joined_args)), NULL);
	split = ((i = 0), ft_split(joined_args, ' '));
	free(joined_args);
	if (!split || !ft_check_two(split))
		return (ft_free_split(split), NULL);
	while (split[i])
		i++;
	while (i--)
		ft_add_to_stack(&stack, ft_atoi(split[i]), 0);
	ft_free_split(split);
	return (ft_set_pos(&stack), stack);
}

t_stack	*ft_resolver(int argc, char **argv)
{
	if (argc >= 2)
		return (ft_args_checker(argc, argv));
	else
		return (NULL);
}
