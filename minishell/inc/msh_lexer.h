/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_lexer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:44:50 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/11 01:25:56 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_LEXER_H
# define MSH_LEXER_H

# include "msh_token.h"

typedef struct s_lexer
{
	char		*input;
	t_token		*lst;
	int			err_malloc;
}	t_lexer;

/**
 * 		lexer.c
 * */
size_t	add_token(t_lexer *lexer, t_tolkien name, char *content, size_t size);
t_token	*lexer(char *input);

/**
 * 		lexer_cmp1.c
 * */
int		token_forbidden(t_lexer *lexer, char *s);
int		token_andor(t_lexer *lexer, char *s);
int		token_parenthesis(t_lexer *lexer, char *s);
int		token_pipe(t_lexer *lexer, char *s);

/**
 * 		lexer_cmp2.c
 * */
int		token_whitespace(t_lexer *lexer, char *s);
int		token_redir(t_lexer *lexer, char *s);
int		token_entrequote(t_lexer *lexer, char *s);
int		token_word(t_lexer *lexer, char *s);

#endif /* MSH_LEXER_H */
