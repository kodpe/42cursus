/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_token_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:55:58 by sloquet           #+#    #+#             */
/*   Updated: 2022/06/21 20:28:56 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	token_forbidden(t_lexer *lexer, char *s)
{
	if (s[0] == ';')
		return (add_token(lexer, T_FORBIDDEN, ";", 1));
	if (s[0] == '\\')
		return (add_token(lexer, T_FORBIDDEN, "\\", 1));
	if (s[0] == '&' && s[1] != '&')
		return (add_token(lexer, T_FORBIDDEN, "&", 1));
	return (0);
}

int	token_andor(t_lexer *lexer, char *s)
{
	if (ft_strlen(s) > 1)
	{
		if (!ft_strncmp(s, "&&", 2))
			return (add_token(lexer, T_ANDOR, "&&", 2));
		if (!ft_strncmp(s, "||", 2))
			return (add_token(lexer, T_ANDOR, "||", 2));
	}
	return (0);
}

int	token_parenthesis(t_lexer *lexer, char *s)
{
	if (s[0] == '(')
		return (add_token(lexer, T_PARENTHESIS, "(", 1));
	if (s[0] == ')')
		return (add_token(lexer, T_PARENTHESIS, ")", 1));
	return (0);
}

int	token_pipe(t_lexer *lexer, char *s)
{
	if (s[0] == '|' && s[1] != '|')
		return (add_token(lexer, T_PIPE, "|", 1));
	return (0);
}
