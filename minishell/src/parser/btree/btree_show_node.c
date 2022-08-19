/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_show_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 23:03:23 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/10 23:03:33 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	btree_show_node(t_btree *n)
{
	ft_dprintf(2, "parent:  : %p\n", n->parent);
	ft_dprintf(2, "-> left  : %p\n", n->left);
	ft_dprintf(2, "-> right : %p\n", n->right);
	ft_dprintf(2, "depth    : %p\n", n->depth);
	ft_dprintf(2, "andor    : %p\n", n->andor);
	ft_dprintf(2, "pipeline : %p\n", n->pipeline);
	if (n->andor)
		print_one_token(n->andor, "NODE ANDOR");
	if (n->pipeline)
		print_token_list(n->pipeline, "LEAF PIPELINE");
}
