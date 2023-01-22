# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/21 08:06:06 by jergashe          #+#    #+#              #
#    Updated: 2023/01/22 07:58:13 by jergashe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
RM = rm -rf
CFLAGS = 
# -Wall -Wextra -Werror
LIBFT = libft_42/libft.a

SRCS = src/push_swap.c	\
		src/parse.c	\
		src/check_array.c	\
		src/errors.c	\
		src/utils.c	\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	git submodule update --init --recursive --remote
	make -C ./libft_42

bonus: $(NAME_BONUS)

clean:
	$(RM) $(OBJS)
	make clean -C ./libft_42

fclean:
	$(RM) $(OBJS) $(NAME) $(NAME_BONUS)
	make fclean -C ./libft_42

re: fclean all

.PHONY: all clean fclean re