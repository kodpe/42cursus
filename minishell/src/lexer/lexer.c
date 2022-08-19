/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:56:12 by chsimon           #+#    #+#             */
/*   Updated: 2022/07/11 01:42:58 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_lexer(t_lexer *lexer)
{
	if (lexer->input)
		free(lexer->input);
	if (lexer->lst)
		destroy_token_list(&lexer->lst);
	free (lexer);
}

static t_lexer	*init_lexer(char *input)
{
	t_lexer	*lexer;

	lexer = ft_calloc(sizeof(t_lexer));
	if (lexer)
	{
		lexer->input = ft_strdup(input);
		if (lexer->input)
		{
			free(input);
			return (lexer);
		}
	}
	free(input);
	free_lexer(lexer);
	return (NULL);
}

size_t	add_token(t_lexer *lexer, t_tolkien name, char *content, size_t size)
{
	if (lexer->err_malloc == 0)
	{
		if (add_back(&lexer->lst, new_token(name, content, size)))
			lexer->err_malloc = 1;
	}
	if (name == T_WORD || name == T_ENTREQUOTE)
		free(content);
	return (size);
}

static void	tokenizer(t_lexer *lexer)
{
	int		i;

	i = 0;
	while (lexer->input[i])
	{
		i += token_forbidden(lexer, &lexer->input[i]);
		i += token_andor(lexer, &lexer->input[i]);
		i += token_parenthesis(lexer, &lexer->input[i]);
		i += token_pipe(lexer, &lexer->input[i]);
		i += token_whitespace(lexer, &lexer->input[i]);
		i += token_redir(lexer, &lexer->input[i]);
		i += token_entrequote(lexer, &lexer->input[i]);
		i += token_word(lexer, &lexer->input[i]);
	}
}

t_token	*lexer(char *input)
{
	t_token	*lst;
	t_lexer	*lexer;

	lexer = init_lexer(input);
	if (!lexer)
		return (NULL);
	tokenizer(lexer);
	if (lexer->err_malloc)
	{
		free_lexer(lexer);
		return (NULL);
	}
	lst = copylst(lexer->lst);
	free_lexer(lexer);
	return (lst);
}
