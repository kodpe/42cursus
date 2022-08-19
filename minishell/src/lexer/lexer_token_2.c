/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_token_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:55:58 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/11 01:42:06 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	token_whitespace(t_lexer *lexer, char *s)
{
	int	i;

	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i++;
	if (i)
		return (add_token(lexer, T_WHITESPACE, " ", i));
	return (0);
}

int	token_redir(t_lexer *lexer, char *s)
{
	if (ft_strlen(s) > 1)
	{
		if (!ft_strncmp(s, "<<", 2))
			return (add_token(lexer, T_REDIR, "<<", 2));
		if (!ft_strncmp(s, ">>", 2))
			return (add_token(lexer, T_REDIR, ">>", 2));
	}
	if (s[0] == '<')
		return (add_token(lexer, T_REDIR, "<", 1));
	if (s[0] == '>')
		return (add_token(lexer, T_REDIR, ">", 1));
	return (0);
}

int	token_entrequote(t_lexer *lexer, char *s)
{
	size_t	i;

	if (!s || !s[0] || (s[0] != '"' && s[0] != '\''))
		return (0);
	i = 1;
	while (s[i] && s[i] != s[0])
		i++;
	if (s[i] == s[0])
		i++;
	if (lexer->err_malloc)
		return (i);
	return (add_token(lexer, T_ENTREQUOTE, ft_strldup(s, i + 1), i));
}

int	token_word(t_lexer *lexer, char *s)
{
	size_t	i;

	if (!s || !s[0] || strchr(NOT_WORD, s[0]))
		return (0);
	i = 0;
	while (s[i])
	{
		if (strchr(NOT_WORD, s[i]))
		{
			if (lexer->err_malloc)
				return (i);
			return (add_token(lexer, T_WORD, ft_strldup(s, i + 1), i));
		}
		i++;
	}
	if (lexer->err_malloc)
		return (i);
	return (add_token(lexer, T_WORD, ft_strldup(s, i + 1), i));
}
