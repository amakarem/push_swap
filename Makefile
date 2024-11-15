# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/17 23:01:14 by aelaaser          #+#    #+#              #
#    Updated: 2024/11/16 00:52:37 by aelaaser         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Werror -Wextra

# Source files
SRCS = 	push_swap.c

OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a
LIBPRINTF = ft_printf/libprintf.a
extralib:
	make -C ft_printf
	make -C libft
# Library name
NAME = pushswap.a

# Default target
all: $(NAME)

# Rule to create the static library
$(NAME): $(OBJS) $(LIBFT) $(LIBPRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(LIBPRINTF)

# Clean up build files
clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	make clean -C libft
	make clean -C ft_printf

fclean: clean
	rm -f $(NAME)
	make fclean -C libft
	make fclean -C ft_printf

re: fclean all

.PHONY: extralib all clean fclean re