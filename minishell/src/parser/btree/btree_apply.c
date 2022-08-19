/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:52:38 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/02 09:17:47 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	btree_apply_infix(t_btree *root, void (*f)(t_btree *))
{
	if (!root || !f)
		return ;
	btree_apply_infix(root->left, f);
	f(root);
	btree_apply_infix(root->right, f);
}

int	get_pipeline(t_btree *root, int (*f)(t_token *))
{
	int	ret;

	ret = 0;
	if (!root)
		return (0);
	if (root->andor)
	{
		ret = get_pipeline(root->left, f);
		if (ret)
			return (ret);
		return (get_pipeline(root->right, f));
	}
	if (root->pipeline)
		return (f(root->pipeline));
	return (0);
}
