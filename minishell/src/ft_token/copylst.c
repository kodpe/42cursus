/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copylst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:25:01 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/29 17:21:25 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*copylst(t_token *t)
{
	t_token	*new;

	new = NULL;
	while (t)
	{
		if (add_back(&new, new_token(t->name, t->content, t->size)))
		{
			destroy_token_list(&new);
			return (NULL);
		}
		t = t->next;
	}
	return (new);
}

t_token	*copy_lst_del(t_token *t)
{
	t_token	*root;

	root = NULL;
	while (t)
	{
		if (t->name != T_DEL)
		{
			if (add_back(&root, new_token(t->name, t->content, t->size)))
			{
				destroy_token_list(&root);
				return (NULL);
			}
		}
		t = t->next;
	}
	return (root);
}

t_token	*copy_lst_del_concat(t_token *t)
{
	t_token	*root;

	root = NULL;
	while (t)
	{
		if (t->name != T_DEL)
		{
			if (add_back(&root, new_token_c(t->name,
						t->content, t->is_concated)))
			{
				destroy_token_list(&root);
				return (NULL);
			}
		}
		t = t->next;
	}
	return (root);
}

t_token	*copy_lst_del_w(t_token *t)
{
	t_token	*root;

	root = NULL;
	while (t)
	{
		if (t->name != T_DEL)
		{
			if (add_back(&root, new_token(t->name, t->content, t->size)))
			{
				destroy_token_list(&root);
				return (NULL);
			}
			if (add_back(&root, new_token(T_WHITESPACE, " ", 1)))
			{
				destroy_token_list(&root);
				return (NULL);
			}
		}
		t = t->next;
	}
	return (root);
}
