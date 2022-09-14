# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 18:23:44 by romvan-d          #+#    #+#              #
#    Updated: 2022/09/13 21:13:08 by romvan-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = $(wildcard source/*.c)

OBJS = ${SRCS:.c=.o}

LIBFT = libft.a

MLX = libmlx.dylib

GNL = libgnl.a

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I ./include -I ./libft -I ./mlx -I ./gnl

$(NAME): $(LIBFT) $(MLX) $(GNL) $(OBJS)
		$(CC) $(CFLAGS) -o $@ -lmlx -Lmlx -framework OpenGL -framework Appkit libft/$(LIBFT) mlx/$(MLX) gnl/$(GNL) $(OBJS)
$(LIBFT) :
		make -C libft bonus

$(MLX) :
		make -C mlx
	
$(GNL) :
		make -C gnl


all:    $(NAME)

clean:
		$(RM) $(OBJS)

fclean:         clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re