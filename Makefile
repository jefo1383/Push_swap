# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yafranco <yafranco@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/13 13:35:48 by yafranco          #+#    #+#              #
#    Updated: 2026/01/13 14:24:12 by yafranco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror

HEADER      = push_swap.h

SRCS        = bench_utils.c \
              benchmark.c \
              clean.c \
			  debug.c \
              ft_init_stack.c \
              ft_normalize_stack.c \
              ft_split.c \
              main.c \
              metrics_flags.c \
              ops_rev_rotate.c \
              ops_rotate.c \
              ops_swap_push.c \
              parsing.c \
              sort_adaptive.c \
              sort_complex.c \
              sort_medium.c \
              sort_simple.c \
              sort_utils.c \
              stack_utils.c

OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

debug: fclean
	$(CC) $(CFLAGS) -g3 -D DEBUG_MODE $(SRCS) -o push_swap_debug
	@echo "Mode DEBUG compilé : ./push_swap_debug"