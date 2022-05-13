SHELL	=/bin/sh
cr		="\e[1;31m   - \e[0;31m"
cg		="\e[1;32m   + \e[0;32m"
cb		="\e[1;34m   > \e[0;34m"
cm		="\e[1;35m   > \e[0;35m"
r		="\e[0m"
n		=$(NAME)" "
size	=$(cr)$(n)$(shell du -bh $(NAME) 2>/dev/null | tr -d '$(NAME) \t')$(r)
sls		=$(shell ls $(SRC_DIR)/*.c 2>/dev/null | tr ' ' '\n')
q_src	=$(shell ls $(SRC_DIR)/*.c 2>/dev/null | wc -l | tr -d '\n')
q_obj	=$(shell ls $(OBJ_DIR)/*.o 2>/dev/null | wc -l | tr -d '\n')
e_src	=$(n)$(q_src)" sources"
e_obj	=$(n)$(q_obj)" objects"
grepr	=$(shell grep -nH --color printf $(SRC_DIR)/*.c | grep -v "ft_printf")
grepgc	=$(shell grep -nH --color getchar $(SRC_DIR)/*.c)

#################################
SRC = $(addsuffix .c,			\
		main					\
		parse					\
		smallsort				\
		smart_insort			\
		aux_display				\
		aux_errors				\
		aux_operations_a		\
		aux_operations_b		\
		aux_operations_double	\
		aux_operations_smart	\
		aux_shortcuts			\
		)
#################################

INC_DIR	=	inc
SRC_DIR	=	src
OBJ_DIR	=	obj
OBJ		=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
SRC_PATH=	$(addprefix $(SRC_DIR)/, $(SRC))

PATH_LIB=	libft/
LIB 	=	libft.a
INC_LIB	=	libft

NAME	=	push_swap

CC		=	gcc
CFLAGS 	=	-Wall -Wextra -Werror -I $(INC_DIR) -I $(INC_LIB)
# CFLAGS 	=	-Wall -Wextra -Werror -g3 -fsanitize=address -I $(INC_DIR) 

RM		=	rm -rf


MFG 	=	--no-print-directory

#########################################

all: 	$(NAME)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
		@mkdir -p $(dir $@)
		@$(CC) $(CFLAGS) -c $< -o $@
#\

		@echo $(cg)$(n)"(@) "$@" (<) "$<$(r)

$(LIB):
		@cd $(PATH_LIB) && $(MAKE) $(MFG) && cd ..

$(NAME):$(LIB) $(OBJ)
		@$(CC) $(CFLAGS) -o $(NAME) $(SRC_PATH) $(PATH_LIB)$(LIB)
		@echo $(cg)$(e_obj)$(r)
		@echo -n $(cg)$(n) && du -bh $(NAME) | tr -d '$(NAME)' && echo -n $(r)

clean:
		@cd $(PATH_LIB) && $(MAKE) $(MFG) fclean && cd ..
		@$(RM) $(OBJ_DIR)
		@echo $(cr)$(e_obj)$(r)

fclean:
		@cd $(PATH_LIB) && $(MAKE) $(MFG) fclean && cd ..
		@$(RM) $(OBJ_DIR) $(NAME)
		@echo $(cr)$(e_obj)$(r)"\n"$(size)

re:		fclean all

#########################################

a:
		@cd $(PATH_LIB) && $(MAKE) $(MFG) a && cd ..
		@echo $(cb)$(e_src) && ls $(SRC_PATH)
		@echo $(cm)$(n)"diff check *"$(r)
		@echo $(sls) | tr ' ' '\n' | sort > o_sls.out
		@echo $(SRC_PATH) | tr ' ' '\n' | sort > o_src.out
		@-diff -y --color --suppress-common-lines o_sls.out o_src.out
		@rm -rf *.out $(PATH_LIB)*.out
		@echo -n $(cm)$(n)"printf check *\n$(grepr)"$(r)
		@echo -n $(cm)$(n)"getchar check *\n$(grepgc)"$(r)

true:
		@cd $(PATH_LIB) && $(MAKE) $(MFG) true && cd ..
#\
		@echo -n $(cm)$(n)"scan nm\n" && nm $(NAME) | grep "ft" && echo -n $(r)

.PHONY: all clean fclean re a true
