/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sublst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:24:26 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/21 17:13:54 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*sublst(t_token *src, t_token *start, t_token *end)
{
	t_token	*new;

	while (src && src != start)
		src = src->next;
	new = NULL;
	while (src)
	{
		if (add_back(&new, new_token(src->name, src->content, src->size)))
		{
			destroy_token_list(&new);
			return (NULL);
		}
		if (src == end)
			break ;
		src = src->next;
	}
	return (new);
}
