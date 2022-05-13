SRC		= ft_printf.c ft_putnbase.c utils.c

CC 		= gcc

CFG		= -Wall -Werror -Wextra

OBJ		= $(SRC:.c=.o)

NAME	= libftprintf.a

all: $(NAME)

%.o: %.c
	$(CC) $(CFG) -c -o $@ $<

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus
