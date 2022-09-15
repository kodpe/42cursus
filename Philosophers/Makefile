r		=	"\033[0m"
n		=	$(NAME)"       "
cr		=	echo $(r)"\033[1;31m   - \033[0;31m"$(n)
cg		=	$(r)"\033[1;32m   + \033[0;32m"$(n)
cb		=	echo "\n"$(r)"\033[1;34m   > \033[0;34m"$(n)
cm		=	echo $(r)"\033[1;35m   > \033[0;35m"$(n)
sls		=	$(shell ls $(SRC_DIR)/*.c 2>/dev/null | tr ' ' '\n')
e_src	=	$(shell ls $(SRC_DIR)/*.c 2>/dev/null | wc -l | tr -d '\n')" sources"
e_obj	=	$(shell ls $(OBJ_DIR)/*.o 2>/dev/null | wc -l | tr -d '\n')" objects"
#-auto-sources-##############002145310822#
SRC = $(addsuffix .c, \
	supervisor \
	init \
	main \
	routine \
	parser \
	mutex \
	time \
	)
#-auto-sources-##############002145310822#

SRC_DIR	=	src
SRC_PATH=	$(addprefix $(SRC_DIR)/, $(SRC))
OBJ_DIR	=	obj
OBJ		=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
DEPS	=	$(OBJ:.o=.d))
# DEPS	=	$(OBJ:.o=.d)

NAME	=	philo

CC		=	cc

CFLAGS 	=	-Wall -Wextra -Werror
# CFLAGS	=	-MMD -Wall -Wextra -Werror -g3
# CFLAGS =	-MMD -Wall -Wextra -Werror -g3 -fsanitize=thread 
# CFLAGS =	-MMD -Wall -Wextra -Werror -g3 -fsanitize=address

INC		=	-I ./inc/
RM		=	rm -rf
#########################################
LIBS	=	-pthread
#########################################
all: 	$(NAME)

$(NAME):$(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(INC) $(LIBS)
		echo -n $(cg) && du -bh $(NAME) | tr -d '$(NAME)' && echo -n $(r)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
		@mkdir -p $(dir $@)
		@$(CC) $(CFLAGS) -c $< -o $@ $(INC)
#\
		@echo -n "\033[0;32m█\033[0m"
#\

		@echo $(cg)"(@) "$@" (<) "$<

clean:
		$(RM) $(OBJ_DIR)
		$(cr)$(e_obj) && echo -n $(r)

fclean:
		$(RM) $(OBJ_DIR) $(NAME)
		$(cr)$(e_obj) && echo -n $(r)

re:		fclean all

#########################################

-include $(DEPS)

.PHONY: all clean fclean re

.SILENT: all clean fclean re $(NAME)
