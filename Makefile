# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chon <chon@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/23 11:51:56 by chon              #+#    #+#              #
#    Updated: 2024/06/05 13:34:18 by chon             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_B = checker
LIBFT_DIR = ./libft
LIBFT = ./libft/libft.a
CFLAGS = -Wall -Werror -Wextra -g3
OBJS_M = $(SRCS_M:.c=.o)
SRCS_M = main.c 
OBJS = $(SRCS:.c=.o)
SRCS = parse.c simple_sort.c complex_sort.c stack_moves.c utils_1.c \
utils_2.c stack_search.c math.c free.c
OBJS_B = $(SRCS_B:.c=.o)
SRCS_B = ./bonus/main_bonus.c

$(NAME): $(OBJS_M) $(OBJS)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(OBJS_M) $(LIBFT) -o $(NAME)

all: $(NAME)

$(NAME_B): $(OBJS) $(OBJS_B)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(OBJS_B) $(LIBFT) -o $(NAME_B)

bonus: $(NAME_B) 

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJS_M) $(OBJS) $(OBJS_B)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)
	rm -f $(NAME_B)

re: fclean all

.PHONY = all clean fclean re
