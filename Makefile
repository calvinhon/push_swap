# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chon <chon@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/23 11:51:56 by chon              #+#    #+#              #
#    Updated: 2024/05/28 16:16:36 by chon             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT_DIR = ./libft
LIBFT = ./libft/libft.a
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g3 
# -lm
OBJS = $(SRCS:.c=.o)
SRCS = main.c parse.c simple_sort.c complex_sort.c stack_moves.c utils_1.c \
utils_2.c stack_search.c math.c free.c
OBJS_B = $(BONUS:.c=.o)
# SRCS_B = ./bonus/

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	$(CC) $(OBJS) $(LIBFT) $(CFLAGS) -o $(NAME)
# $(CC) $(CFLAGS) $(LIBFT) $(OBJS) -o $(NAME)

all: $(NAME)

bonus: $(NAME) $(OBJS)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(LIBFT) $(OBJS_B) -o $(NAME)

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJS) $(OBJS_B)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY = all clean fclean re
