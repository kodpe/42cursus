/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 23:02:14 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/10 23:24:37 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	btree_destroy_node(t_btree *node)
{
	if (!node)
		return ;
	if (node->pipeline)
		destroy_token_list(&node->pipeline);
	if (node->andor)
		destroy_token_list(&node->andor);
	free(node);
}

void	btree_destroy(t_btree **root)
{
	if (!*root)
		return ;
	if ((*root)->left)
		btree_destroy(&((*root)->left));
	if ((*root)->right)
		btree_destroy(&((*root)->right));
	btree_destroy_node((*root));
	*root = NULL;
}
