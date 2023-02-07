/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_tags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 09:38:22 by kchaouki          #+#    #+#             */
/*   Updated: 2023/02/07 10:07:57 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	ft_init_with_0(char **str, int size)
{
	int	i;

	i = 0;
	while (i < size)
		(*str)[i++] = '0';
	(*str)[i] = '\0';
}

static int	ft_set_tag_by_head(t_stack *stack, char **tagged, \
								int head, int *positions)
{
	int		stack_size;
	int		count;
	int		i;
	int		j;

	stack_size = ft_stack_size(stack);
	ft_init_with_0(tagged, stack_size);
	i = ft_pos_index(stack, head);
	count = 0;
	j = -1;
	while (++j < 2)
	{
		if (j == 1)
			i = 0;
		while (i < stack_size)
		{
			if (positions[i] >= head && (*tagged)[i] == '0')
				head = ((((*tagged)[i] = '1'), count++), positions[i]);
			i++;
		}
	}
	return (count);
}

char	*ft_best_marker(t_stack	*stack, int *positions, int stack_size)
{
	char	*tagged_tmp;
	char	*tagged;
	t_stack	*tmp;
	int		count;
	int		old_count;

	tagged = malloc(stack_size + 1);
	tagged_tmp = malloc(stack_size + 1);
	if (!tagged || !tagged_tmp)
		return (NULL);
	tmp = stack;
	old_count = 0;
	while (tmp)
	{
		count = ft_set_tag_by_head(stack, &tagged_tmp, tmp->pos, positions);
		if (count > old_count)
		{
			old_count = count;
			ft_strlcpy(tagged, tagged_tmp, stack_size + 1);
		}
		tmp = tmp->next;
	}
	return (free(tagged_tmp), tagged);
}

void	ft_tags_to_stack(t_stack **stack)
{
	t_stack	*tmp_stack;
	int		stack_size;
	int		*positions;
	char	*tags;
	char	*tmp;

	tmp_stack = (*stack);
	stack_size = ft_stack_size(*stack);
	positions = ft_pos_to_arr(*stack);
	tags = ft_best_marker((*stack), positions, stack_size);
	free(positions);
	tmp = tags;
	while (tmp_stack)
	{
		tmp_stack->tag = *(tags++) - 48;
		tmp_stack = tmp_stack->next;
	}
	free(tmp);
}
