NAME	= 	btc

SRC		= 	main.cpp BitcoinExchange.cpp utils.cpp

CFLAGS	=	-std=c++98 -Wall -Wextra -Werror

OBJ_DIR =	obj/
OBJ		= $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

DEPS	= $(OBJ:.o=.d)

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(CFLAGS) -o $(NAME) $(OBJ)

$(OBJ_DIR)%.o: %.cpp
	mkdir -p $(dir $@)
	c++ $(CFLAGS) -MMD -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean
	make all

-include $(DEPS)

.PHONY : all clean fclean re
