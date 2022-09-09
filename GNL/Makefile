# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/09 16:04:50 by romvan-d          #+#    #+#              #
#    Updated: 2022/09/09 16:42:49 by romvan-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgnl.a

SRCS = get_next_line.c\
		get_next_line_utils.c\
		
OBJS = ${SRCS:.c=.o}

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror

.c.o:   ${SRCS}
		${CC} ${CFLAGS} -c -o $@ $<

${NAME}:        ${OBJS}
		ar r $(NAME) ${OBJS}

all:    ${NAME}

clean:
		${RM} ${OBJS}

fclean:         clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re