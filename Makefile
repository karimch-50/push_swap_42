# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/04 16:20:20 by kchaouki          #+#    #+#              #
#    Updated: 2023/02/07 10:30:43 by kchaouki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OPERATIONS = mandatory/operations/stack_operations.c\
			 mandatory/operations/ft_rev_rotate.c \
			 mandatory/operations/ft_rotate.c \
			 mandatory/operations/ft_push.c \
			 mandatory/operations/ft_swap.c

INPUTS_CHECKER = mandatory/input_checker/ft_add_to_stack.c \
				 mandatory/input_checker/ft_join_args.c \
				 mandatory/input_checker/ft_args_checker.c \
				 mandatory/input_checker/ft_isspace.c \
				 mandatory/input_checker/ft_set_pos.c

SHARED = mandatory/shared/ft_clone_stack.c \
		 mandatory/shared/ft_free.c \
		 mandatory/shared/ft_struct_op.c \
		 mandatory/shared/ft_find_index.c \
		 mandatory/shared/ft_calculation.c \
		 mandatory/shared/ft_pos_index.c \
		 mandatory/shared/ft_apply_operation.c \
		 mandatory/shared/ft_optimal_steps.c \
		 mandatory/shared/ft_pos_to_arr.c \
		 mandatory/shared/ft_need_rotate.c \
		 mandatory/shared/ft_need_swap.c \
		 mandatory/shared/ft_set_tags.c \
		 mandatory/shared/ft_stack_is_sorted.c \
		 mandatory/shared/ft_stack_size.c

SHARED_B = mandatory/shared/ft_free.c \
		   mandatory/shared/ft_stack_is_sorted.c \

SRCS = mandatory/main.c mandatory/push_swap.c $(SHARED) $(INPUTS_CHECKER) $(OPERATIONS)

SRCS_B = bonus/main.c \
		 bonus/ft_checker.c \
		 bonus/get_next_line.c \
		 bonus/get_next_line_utils.c \
		 $(SHARED_B) $(INPUTS_CHECKER) $(OPERATIONS)

NAME = push_swap

NAME_B = checker

LIBFT = mandatory/libft/libft.a

OBJS = $(SRCS:.c=.o)

OBJS_B = $(SRCS_B:.c=.o)

FLAGS = -Wall -Wextra -Werror -I includes

CCe = cc $(FLAGS)

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C mandatory/libft && make clean -C mandatory/libft

%.o : %.c
	$(CCe) -c $< -o $@

$(NAME): $(OBJS)
	$(CCe) $(OBJS) $(LIBFT) -o $(NAME)

$(NAME_B): $(OBJS_B)
	$(CCe) $(OBJS_B) $(LIBFT) -o $(NAME_B)

clean:
	rm -rf $(OBJS) $(OBJS_B)

bonus: $(LIBFT) $(NAME_B)

fclean: clean
	rm -rf mandatory/libft/libft.a $(NAME) $(NAME_B)

re: fclean all

.PHONY: fclean clean all re libft