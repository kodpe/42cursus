SRCS	= srcs/do_op.c srcs/tools.c
OBJS	= ${SRCS:.c=.o}
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
NAME	= do-op

.c.o :	
	${CC} -I includes ${CFLAGS} -c $< -o ${<:.c=.o}

all : ${OBJS}
	${CC} -o ${NAME} ${OBJS}

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY: all clean fclean re	
