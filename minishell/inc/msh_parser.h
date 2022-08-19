/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:03:30 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/28 14:11:09 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_PARSER_H
# define MSH_PARSER_H

# include "msh_token.h"

# define ERROR ": syntax error near unexpected token `"
# define ERR_SS_SHELL ": No sous shell in MY HOUSE"

typedef struct s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	struct s_btree	*parent;
	t_token			*andor;
	t_token			*pipeline;
	int				depth;
	int				status;
}	t_btree;

t_btree	*parser(t_token *tolkien, int *exitcode);
/* 1 */
int		check_one_input(t_token *tolkien);
/* 2 */
int		valid_pipeline(t_token *pipeline);
/* 3 */
int		valid_cmd(t_token *pipeline);

/**
 * 		check_one_input/
 * */
int		content_is_valid(t_token *t);
int		valid_andor(t_token *t);
int		valid_parenthesis(t_token *t, int show);
int		check_parenthesis_empty(t_token *t);
int		check_parenthesis_prev(t_token *t);
int		check_parenthesis_next(t_token *t);
int		check_open(t_token *t, int show);
int		check_close(t_token *t, int show);
/**
 * 		btree/
 * */
t_btree	*btree_create(t_token *tolkien);
void	btree_destroy(t_btree **root);
t_btree	*btree_create_andor_node(t_token *andor);
t_btree	*btree_create_pipeline_leaf(t_token *pipeline);
void	btree_show_2d(t_btree *root);
void	btree_show_node(t_btree *n);
void	btree_apply_infix(t_btree *root, void (*f)(t_btree *));
int		get_pipeline(t_btree *root, int (*f)(t_token *));

/**
 * 		utils/syntax_error_msg.c
 * */
void	message_err_sous_shell(void);
void	message_erreur(char *str, int show);
void	message_erreur_2(char *str);

#endif /* MSH_PARSER_H */
