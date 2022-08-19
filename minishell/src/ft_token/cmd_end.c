/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_end.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:38:34 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/01 18:39:03 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*cmd_end(t_token *lst)
{
	t_token	*t;

	t = lst;
	while (t && t->next)
	{
		if (t->name == T_PIPE)
			return (t->prev);
		t = t->next;
	}
	return (t);
}
