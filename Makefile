# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 18:23:44 by romvan-d          #+#    #+#              #
#    Updated: 2022/10/25 15:10:23 by romvan-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = source/fdf_algorithm.c\
		source/fdf_free.c\
		source/fdf_hooks.c\
		source/fdf_mapping.c\
		source/fdf_parsing.c\
		source/fdf_transformations.c\
		source/fdf_utils.c\
		source/main.c\

OBJS = ${SRCS:.c=.o}

LIBFT = libft.a

MLX = libmlx.dylib

GNL = libgnl.a

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I ./include -I ./libft -I ./mlx -I ./gnl

# SANITIZE = -g -fsanitize=address 

LIBS =  -lmlx -Lmlx -framework OpenGL -framework Appkit

$(NAME): libft/$(LIBFT) $(MLX) gnl/$(GNL) $(OBJS)
		$(CC) $(SANITIZE) $(CFLAGS) $(LIBS) -o $@ libft/$(LIBFT) $(MLX) gnl/$(GNL) $(OBJS)
libft/$(LIBFT) :
		make -C libft

$(MLX) :
		make -C mlx
		mv ./mlx/$(MLX) .

gnl/$(GNL) :
		make -C gnl


all:    $(NAME)

clean:
		$(RM) $(OBJS)
		make clean -C gnl
		make clean -C libft

fclean:         clean
		$(RM) $(NAME) $(MLX)
		make fclean -C gnl
		make fclean -C libft
		make clean -C mlx
		
re: fclean all

.PHONY: all clean fclean re