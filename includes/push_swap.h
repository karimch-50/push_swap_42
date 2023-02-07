/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:20:33 by kchaouki          #+#    #+#             */
/*   Updated: 2023/02/07 10:10:42 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../mandatory/libft/libft.h"
# include <limits.h>

void	push_swap(int argc, char **argv);

/*#######################################################################
#	 							STRUCTS									#
#######################################################################*/

typedef struct s_stack
{
	int				num;
	int				pos;
	int				tag;
	struct s_stack	*next;
}	t_stack;

typedef struct s_operations
{
	int					ra;
	int					rra;
	int					rb;
	int					rrb;
	int					rr;
	int					rrr;
}	t_operations;

/*#######################################################################
#	 						 ARGS CHECKER								#
########################################################################*/

void	ft_add_to_stack(t_stack **list, int content, int pos);
t_stack	*ft_resolver(int argc, char **argv);
char	*ft_join_args(char *s1, char *s2);
void	ft_set_pos(t_stack **stack);
int		ft_isspace(int c);

/*#######################################################################
#	  							OPERATIONS								#
#######################################################################*/

void	push(t_stack **stack, t_stack **to_push);
void	pop(t_stack **stack, t_stack **poped);

void	ft_swap(t_stack **stack, char *rule_name);
void	ft_rotate(t_stack **stack, char *rule_name);
void	ft_rev_rotate(t_stack **stack, char *rule_name);
void	ft_p(t_stack **stack_a, t_stack **stack_b, char a_b, int shee);

/*#######################################################################
#								  SHARED								#
#######################################################################*/

/* FREE */
void	ft_free_stack(t_stack **stack);
void	ft_free_split(char **split);

/* PREPARING STACK A TO PUSH TO STACK B */
void	ft_tags_to_stack(t_stack **stack);
char	*ft_best_marker(t_stack	*stack, int *positions, int stack_size);
int		*ft_pos_to_arr(t_stack *stack);
int		ft_need_swap(t_stack *stack);
int		ft_need_rotate(t_stack *stack, int pos);

int		ft_find_index(t_stack *stack, int pos);
t_stack	*ft_clone_stack(t_stack **stack);
int		ft_pos_index(t_stack *stack, int pos);
int		ft_stack_size(t_stack *stack);
int		ft_stack_is_sorted(t_stack	*stack);

void	ft_initial_op_struct(t_operations *op);
void	ft_set_op(t_operations *old, t_operations *new);
int		ft_calculator(int stack_a_op, int stack_b_op, t_operations *op);
int		ft_optimal(t_stack *stack_a, t_stack *stack_b, t_operations *op);

/* PREPARING STACK B TO PUSH BACK TO STACK A*/
void	ft_apply_rr(t_stack **stack_a, t_stack **stack_b, int *rr);
void	ft_apply_rrr(t_stack **stack_a, t_stack **stack_b, int *rrr);
void	ft_apply_rx(t_stack **stack_a, t_stack **stack_b, int *ra, int *rb);
void	ft_apply_rrx(t_stack **stack_a, t_stack **stack_b, int *rra, int *rrb);

#endif