/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:15:26 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/11 02:12:15 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	skip_parenthesis(t_token **t)
{
	int	i;

	i = 0;
	while (*t)
	{
		if ((*t)->name == T_PARENTHESIS && (*t)->content[0] == ')')
			i++;
		else if ((*t)->name == T_PARENTHESIS && (*t)->content[0] == '(')
			i--;
		if ((*t)->prev)
			*t = (*t)->prev;
		if (i == 0)
			return ;
	}
	ft_dprintf(2, "%s\n", "btree.c, skip_parenthesis, critical err '('");
	return ;
}

static int	find_andor(t_token *root, t_token **andor)
{
	t_token	*t;

	t = token_last(root);
	while (t && t->prev)
	{
		if (t->name == T_PARENTHESIS && t->content[0] == ')')
			skip_parenthesis(&t);
		if (t->name == T_ANDOR)
		{
			if (add_back(andor, new_token(t->name, t->content, t->size)))
			{
				destroy_token_list(andor);
				return (-1);
			}
			return (1);
		}
		t = t->prev;
	}
	return (0);
}

static t_token	*ptr_and(t_token *root)
{
	t_token	*t;

	t = token_last(root);
	while (t && t->prev)
	{
		if (t->name == T_PARENTHESIS && t->content[0] == ')')
			skip_parenthesis(&t);
		if (t->name == T_ANDOR)
			return (t);
		t = t->prev;
	}
	return (NULL);
}

static int	btree(t_btree **par, t_token *oldlst)
{
	t_token	*andor;
	t_token	*t;

	t = trim_parenthesis(oldlst);
	if (!t)
		return (ERR_MALLOC);
	andor = NULL;
	if (find_andor(t, &andor) < 0)
		return (ERR_MALLOC);
	if (andor)
	{
		*par = btree_create_andor_node(andor);
		if (btree(&((*par)->left), sublst(t, t, ptr_and(t)->prev)))
			return (ERR_MALLOC);
		if (btree(&((*par)->right), sublst(t, ptr_and(t)->next, token_last(t))))
			return (ERR_MALLOC);
		destroy_token_list(&t);
	}
	else
		*par = btree_create_pipeline_leaf(t);
	return (0);
}

t_btree	*btree_create(t_token *tolkien)
{
	t_btree	*parent;

	if (SHOW_TOKEN)
		print_token_list(tolkien, "TOKEN LIST");
	if (btree(&parent, tolkien))
	{
		btree_destroy(&parent);
		return (NULL);
	}
	tolkien = NULL;
	if (SHOW_BTREE_VERBOSE)
		btree_apply_infix(parent, btree_show_node);
	if (SHOW_BTREE)
		btree_show_2d(parent);
	return (parent);
}
