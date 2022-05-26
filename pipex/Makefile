r		=	"\033[0m"
n		=	$(NAME)"       "
cr		=	echo $(r)"\033[1;31m   - \033[0;31m"$(n)
cg		=	$(r)"\033[1;32m   + \033[0;32m"$(n)
cb		=	echo "\n"$(r)"\033[1;34m   > \033[0;34m"$(n)
cm		=	echo $(r)"\033[1;35m   > \033[0;35m"$(n)
sls		=	$(shell ls $(SRC_DIR)/*.c 2>/dev/null | tr ' ' '\n')
e_src	=	$(shell ls $(SRC_DIR)/*.c 2>/dev/null | wc -l | tr -d '\n')" sources"
e_obj	=	$(shell ls $(OBJ_DIR)/*.o 2>/dev/null | wc -l | tr -d '\n')" objects"
grepr	=	$(shell grep -nH --color printf $(SRC_DIR)/*.c | grep -v "ft_printf")
grepgc	=	$(shell grep -nH --color getchar $(SRC_DIR)/*.c)

#################################
SRC = $(addsuffix .c,			\
		create					\
		destroy					\
		error					\
		execute					\
		main					\
		debug					\
		)
#################################

#################################
SRC_BONUS = $(addsuffix .c,			\
		create_bonus					\
		destroy_bonus					\
		error_bonus					\
		execute_bonus					\
		main_bonus					\
		debug_bonus					\
		)
#################################

SRC_DIR	=	src
SRC_PATH=	$(addprefix $(SRC_DIR)/, $(SRC))
OBJ_DIR	=	obj
OBJ		=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
DEPS	=	$(OBJ:.o=.d)

SRC_DIR_BONUS 	= src_bonus
SRC_PATH_BONUS	=	$(addprefix $(SRC_DIR_BONUS)/, $(SRC_BONUS))
OBJ_DIR_BONUS	=	obj_bonus
OBJ_BONUS		=	$(addprefix $(OBJ_DIR_BONUS)/, $(SRC_BONUS:.c=.o))

NAME	=	pipex

CC		=	gcc
CFLAGS 	=	-MMD -Wall -Wextra -Werror -g
INC		=	-I ./inc/
RM		=	rm -rf

PATH_LIB=	libft/
LIB 	=	libft.a
INC_LIB	=	libft
MAKELIB =	$(MAKE) $(MFG) -C $(PATH_LIB)
MFG 	=	--no-print-directory

# VALGRIND=	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes
# --leak-check=full: "each individual leak will be shown in detail"
# --show-leak-kinds=all: Show all of "definite, indirect, possible, reachable" leak kinds.
# --track-origins=yes: This tracks the origins of uninitialized values.
# --verbose: Can tell you about unusual behavior of your program.
# --log-file: Write to a file. Useful when output exceeds terminal space.

#########################################

all: 	$(NAME)

$(NAME):$(LIB) $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(INC) $(PATH_LIB)$(LIB)
		echo -n $(cg) && du -bh $(NAME) | tr -d '$(NAME)' && echo -n $(r)

$(LIB):
		$(MAKELIB)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
		@mkdir -p $(dir $@)
		@$(CC) $(CFLAGS) -c $< -o $@ $(INC)
#\

		@echo $(cg)"(@) "$@" (<) "$<

$(OBJ_DIR_BONUS)/%.o:$(SRC_DIR_BONUS)/%.c
		@mkdir -p $(dir $@)
		@$(CC) $(CFLAGS) -c $< -o $@ $(INC)
#\

		@echo $(cg)"(@) "$@" (<) "$<

bonus:$(LIB) $(OBJ_BONUS)
		$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME) $(INC) $(PATH_LIB)$(LIB)
		echo -n $(cg) && du -bh $(NAME) | tr -d '$(NAME)' && echo -n $(r)

clean:
		$(MAKELIB) clean
		$(RM) $(OBJ_DIR) $(OBJ_DIR_BONUS)
		$(cr)$(e_obj)

fclean:
		$(MAKELIB) fclean
		$(RM) $(OBJ_DIR) $(OBJ_DIR_BONUS) $(NAME)
		$(cr)$(e_obj) && $(cr)

re:		fclean all

#########################################
a:
		$(cb)$(e_src) && ls $(SRC_PATH)
		$(cm)"diff check *"
		echo $(sls) | tr ' ' '\n' | sort > o_sls.out
		echo $(SRC_PATH) | tr ' ' '\n' | sort > o_src.out
		-diff -y --color --suppress-common-lines o_sls.out o_src.out && rm *.out

-include $(DEPS)
.PHONY: all clean fclean re a bonus

.SILENT: all clean fclean re a bonus $(NAME) $(LIB)
