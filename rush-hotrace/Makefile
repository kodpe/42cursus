# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/04 13:08:22 by ggiquiau          #+#    #+#              #
#    Updated: 2021/12/12 19:49:05 by ggiquiau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 			= buf_write.c main.c ft_strlen.c ft_memcpy.c ft_strjoin.c ft_substr.c ft_strdup.c ft_bzero.c ft_strcmp.c get_next_line.c get_next_line_utils.c utils.c error.c


OBJS 			= ${SRCS:.c=.o}

HEADERS			= hotrace.h get_next_line.h

CC  			=  cc

CFLAGS			= -Wall -Wextra -Werror
LFLAGS			=

NAME 			= hotrace


RM 				= rm -f

%.o:			%.c ${HEADERS}
				${CC} -c ${CFLAGS} -o $@ $<


all:			${NAME}

		
${NAME}:		${OBJS}
				${CC} ${OBJS} ${CFLAGS} ${LFLAGS} -o $@

clean:
				${RM} ${OBJS}

fclean:
				${RM} ${OBJS} ${NAME}

re:
				${MAKE} fclean
				${MAKE} all
.PHONY:			all clean fclean re
