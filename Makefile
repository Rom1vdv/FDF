# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 18:23:44 by romvan-d          #+#    #+#              #
#    Updated: 2022/09/07 12:25:51 by romvan-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = $(wildcard source/*.c)

OBJS = ${SRCS:.c=.o}

LIBFT = libft.a

MLX = mlx.dylib

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I ./include -I ./libft -I ./mlx -I ./GNL

$(NAME): $(LIBFT) $(MLX) $(OBJS)
		$(CC) $(CFLAGS) -o $@ $(LIBFT) $(MLX) $(OBJS)
		
$(LIBFT) :
		make -C libft

$(MLX) :
		make -C mlx

all:    $(NAME)

clean:
		$(RM) $(OBJS)

fclean:         clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re