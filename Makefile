# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/21 08:06:06 by jergashe          #+#    #+#              #
#    Updated: 2023/01/25 11:21:26 by jergashe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker
CC = cc
RM = rm -rf
CFLAGS = 
# -Wall -Wextra -Werror
LIBFT = libft_42/libft.a

SRCS = src/push_swap.c	\
		src/parse.c	\
		src/check_array.c	\
		src/errors.c	\
		src/init_stack.c	\
		src/node.c	\
		src/utils.c	\
		src/sort_array.c	\
		src/sort.c	\
		src/sort_utils.c	\
		src/stack_manipulation/push_stack.c	\
		src/stack_manipulation/free_stack.c	\
		src/stack_manipulation/swap_stack.c	\
		src/stack_manipulation/rotate_stack.c	\
		src/stack_manipulation/print_stack.c	\
		src/stack_manipulation/pop_stack.c	\
		
BONUS_SRCS = bonus_src/push_swap_checker.c	\
		bonus_src/check_array.c	\
		bonus_src/errors.c	\
		bonus_src/init_stack.c	\
		bonus_src/node.c	\
		bonus_src/parse.c	\
		bonus_src/sort_array.c	\
		bonus_src/sort_utils.c	\
		bonus_src/stack_manipulation/push_stack.c	\
		bonus_src/stack_manipulation/free_stack.c	\
		bonus_src/stack_manipulation/swap_stack.c	\
		bonus_src/stack_manipulation/rotate_stack.c	\
		bonus_src/stack_manipulation/pop_stack.c	\

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	git submodule update --init --recursive --remote
	make -C ./libft_42

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(LIBFT) $(BONUS_OBJS)
	@$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS) $(LIBFT)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)
	make clean -C ./libft_42

fclean:
	$(RM) $(OBJS) $(NAME) $(BONUS_OBJS) $(BONUS_NAME)
	make fclean -C ./libft_42

re: fclean all

.PHONY: all clean fclean re