r		=	"\033[0m"
n		=	$(NAME)"       "
cr		=	echo $(r)"\033[1;31m   - \033[0;31m"$(n)
cg		=	$(r)"\033[1;32m   + \033[0;32m"$(n)
cb		=	echo "\n"$(r)"\033[1;34m   > \033[0;34m"$(n)
cm		=	echo $(r)"\033[1;35m   > \033[0;35m"$(n)
sls		=	$(shell ls $(SRC_DIR)/*.c 2>/dev/null | tr ' ' '\n')
e_src	=	$(shell ls $(SRC_DIR)/*.c 2>/dev/null | wc -l | tr -d '\n')" sources"
e_obj	=	$(shell ls $(OBJ_DIR)/*.o 2>/dev/null | wc -l | tr -d '\n')" objects"
#-auto-sources-##############502109290722#
SRC = $(addsuffix .c, \
	ft_token/add_back \
	ft_token/token_size \
	ft_token/new_token \
	ft_token/token_last \
	ft_token/sublst \
	ft_token/destroy_token_list \
	ft_token/print_token \
	ft_token/sort_token_content \
	ft_token/trim_parenthesis \
	ft_token/cmd_end \
	ft_token/add_token_list \
	ft_token/copylst \
	ft_token/token_convert \
	ft_token/token_valid \
	get_line_input \
	errors_msg \
	main \
	parser/1_check_one_input \
	parser/utils/syntax_error_msg \
	parser/check_one_input/valid_andor \
	parser/check_one_input/parenthesis \
	parser/check_one_input/parenthesis_utils \
	parser/check_one_input/content_is_valid \
	parser/parser \
	parser/btree/btree_create_node \
	parser/btree/btree_apply \
	parser/btree/btree_show_node \
	parser/btree/btree_destroy \
	parser/btree/btree_create \
	parser/btree/btree_show2d \
	parser/3_check_cmd_redir \
	parser/2_check_pipeline \
	builtins/builtin_export \
	builtins/builtin_unset \
	builtins/builtin_env \
	builtins/builtin_pwd \
	builtins/builtin_echo \
	builtins/builtin_cd \
	builtins/builtin_exit \
	pre_exec/fill_cmd \
	pre_exec/cmd_destructor \
	pre_exec/cmd_print \
	pre_exec/create_pipeline \
	pre_exec/wildcard/filter_files \
	pre_exec/wildcard/wildcard \
	pre_exec/wildcard/get_files \
	pre_exec/wildcard/valid_motif \
	pre_exec/wildcard/wildcard_2 \
	pre_exec/prep \
	pre_exec/save_res_io \
	pre_exec/concat \
	pre_exec/concat_2 \
	pre_exec/execute_pipeline \
	pre_exec/pre_exec \
	pre_exec/cmd_split \
	pre_exec/cmd_create \
	signal \
	lexer/lexer \
	lexer/lexer_token_1 \
	lexer/lexer_token_2 \
	execution/execute_builtin \
	execution/destroy_exit \
	execution/exec \
	execution/test_access \
	execution/here_doc \
	execution/exitcode \
	execution/child_process \
	execution/pathfinder \
	execution/create_here_doc \
	execution/set_redir \
	execution/pidtab \
	execution/set_redir_in \
	execution/one_pipe \
	environment/env_destroy \
	environment/env_del \
	environment/env_expandone \
	environment/env_replace \
	environment/env_init \
	environment/env_get \
	environment/env_expander_heredoc \
	environment/env_add \
	environment/env_exitcode \
	environment/env_last_dollar \
	environment/env_expander \
	environment/env_size \
	environment/env_isname \
	environment/env_show \
	environment/env_spllit_token \
	)
#-auto-sources-##############502109290722#

SRC_DIR	=	src
SRC_PATH=	$(addprefix $(SRC_DIR)/, $(SRC))
OBJ_DIR	=	obj
OBJ		=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
DEPS	=	$(OBJ:.o=.d))
# DEPS	=	$(OBJ:.o=.d)

NAME	=	minishell

CC		=	gcc
CFLAGS 	=	-MMD -Wall -Wextra -Werror -g3
FCFLAGS =	-MMD -Wall -Wextra -Werror -g3 -fsanitize=address
INC		=	-I ./inc/
RM		=	rm -rf

PATH_LIB=	libft/
LIB 	=	libft.a
INC_LIB	=	libft
MAKELIB =	$(MAKE) $(MFG) -C $(PATH_LIB)
MFG 	=	--no-print-directory

LIBS	=	-lreadline

#########################################
all: 	$(NAME)

$(NAME):$(LIB) $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(INC) $(PATH_LIB)$(LIB) $(LIBS)
		echo -n $(cg) && du -bh $(NAME) | tr -d '$(NAME)' && echo -n $(r)

$(LIB):
		$(MAKELIB)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
		@mkdir -p $(dir $@)
		@$(CC) $(CFLAGS) -c $< -o $@ $(INC)
#\

		@echo $(cg)"(@) "$@" (<) "$<

testf: $(LIB) $(OBJ)
	$(CC) $(FCFLAGS) $(OBJ) -o $(NAME) $(INC) $(PATH_LIB)$(LIB) $(LIBS)
	@echo $(r)
	@./$(NAME)

val:
		valgrind \
		--show-leak-kinds=all \
		--track-origins=yes \
		--leak-check=full \
		--track-fds=yes \
		./$(NAME)
#--suppressions=suppr.valgrind
#--trace-children=yes 

testvre:	re
	make val

testv: all
	make val

clean:
		$(MAKELIB) clean
		$(RM) $(OBJ_DIR)
		$(cr)$(e_obj)

fclean:
		$(MAKELIB) fclean
		$(RM) $(OBJ_DIR) $(NAME)
		$(cr)$(e_obj)

re:		fclean
	make all

bonus: all

#########################################
a:
		$(cb)$(e_src) && ls $(SRC_PATH)

-include $(DEPS)

.PHONY: all clean fclean re bonus a

.SILENT: all clean fclean re bonus a $(NAME) $(LIB)
