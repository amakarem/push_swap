# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/17 23:01:14 by aelaaser          #+#    #+#              #
#    Updated: 2024/11/25 16:06:45 by aelaaser         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Werror -Wextra

# Source files
SRCS = 	stack.c stack_ext.c algo_push.c algo_rotate.c algo_rr.c algo_swap.c main.c helper.c maping_sort.c maping_helper.c move.c utils.c

OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a
# Library name
NAME = push_swap

# Default target
all: $(NAME)

# Rule to create the static library
$(NAME): $(OBJS) $(LIBFT) $(LIBPRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(LIBPRINTF)

# Ensure libft is built first
$(LIBFT):
	make -C libft

# Clean up build files
clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re