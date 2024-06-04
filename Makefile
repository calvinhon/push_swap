# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chon <chon@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/23 11:51:56 by chon              #+#    #+#              #
#    Updated: 2024/06/04 16:52:44 by chon             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_B = checker
LIBFT_DIR = ./libft
LIBFT = ./libft/libft.a
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g3
OBJS_M = $(SRCS_M:.c=.o)
SRCS_M = main.c 
OBJS = $(SRCS:.c=.o)
SRCS = parse.c simple_sort.c complex_sort.c stack_moves.c utils_1.c \
utils_2.c stack_search.c math.c free.c
OBJS_B = $(SRCS_B:.c=.o)
SRCS_B = ./bonus/checker_bonus.c
# ./bonus/main_bonus.c ./bonus/parse_bonus.c \
# ./bonus/simple_sort_bonus.c ./bonus/complex_sort_bonus.c \
# ./bonus/stack_moves_bonus.c ./bonus/utils_1_bonus.c ./bonus/utils_2_bonus.c \
# ./bonus/stack_search_bonus.c ./bonus/math_bonus.c ./bonus/free_bonus.c \

$(NAME): $(OBJS) $(OBJS_M)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(LIBFT) $(OBJS) $(OBJS_M) -o $(NAME)

all: $(NAME)

$(NAME_B): $(OBJS) $(OBJS_B)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(LIBFT) $(OBJS_B) $(OBJS) -o $(NAME_B)

bonus: $(NAME_B) 

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJS) $(OBJS_B)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)
	rm -f $(OBJS_B)

re: fclean all

.PHONY = all clean fclean re
