/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_token_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:40:40 by chsimon           #+#    #+#             */
/*   Updated: 2022/07/12 17:58:03 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*add_token_list(t_token **ptr, t_token *expand)
{
	t_token	*third;

	third = NULL;
	if ((*ptr)->next)
		third = (*ptr)->next;
	(*ptr)->next = expand;
	expand->prev = *ptr;
	expand = token_last(expand);
	expand->next = third;
	if (third)
		third->prev = expand;
	(*ptr)->name = T_DEL;
	return (third);
}
