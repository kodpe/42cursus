/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_back.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:23:43 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/01 18:23:5 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	add_back(t_token **lst, t_token *new)
{
	t_token	*root;

	if (!new)
		return (1);
	if (!*lst)
	{
		*lst = new;
		return (0);
	}
	root = *lst;
	while (*lst && (*lst)->next)
		*lst = (*lst)->next;
	(*lst)->next = new;
	new->prev = *lst;
	new->pos = (*lst)->pos + 1;
	*lst = root;
	return (0);
}
