/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content_is_valid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 16:41:45 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/02 09:32:37 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	content_is_valid(t_token *t)
{
	while (t)
	{
		if (t->name == T_FORBIDDEN)
			break ;
		if (t->name == T_ENTREQUOTE)
			if (t->size == 1 || t->content[t->size - 1] != t->content[0])
				break ;
		t = t->next;
	}
	if (!t)
		return (0);
	message_erreur(t->content, 1);
	return (2);
}
