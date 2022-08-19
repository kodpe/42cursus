/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:22:57 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/29 22:23:27 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*new_token(t_tolkien name, char *content, size_t size)
{
	t_token	*new;

	new = (t_token *)malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->name = name;
	new->content = ft_strdup(content);
	if (!new->content)
	{
		free(new);
		return (NULL);
	}
	new->pos = 0;
	new->is_concated = 0;
	new->size = size;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_token	*new_token_c(t_tolkien name, char *content, int concat)
{
	t_token	*new;

	new = (t_token *)malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->name = name;
	new->content = ft_strdup(content);
	if (!new->content)
	{
		free(new);
		return (NULL);
	}
	new->pos = 0;
	new->is_concated = concat;
	new->size = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
