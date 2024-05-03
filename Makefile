# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chon <chon@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/23 11:51:56 by chon              #+#    #+#              #
#    Updated: 2024/04/30 16:50:08 by chon             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT_DIR = ./libft
LIBFT = ./libft/libft.a
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g3
OBJS = $(SRCS:.c=.o)
SRCS = main.c list_op_1.c list_op_2.c sort.c
OBJS_B = $(BONUS:.c=.o)
# SRCS_B = ./bonus/

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(LIBFT) $(OBJS) -o $(NAME)

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
