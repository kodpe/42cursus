/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:18:14 by chsimon           #+#    #+#             */
/*   Updated: 2022/07/29 17:13:40 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pre_exec(t_btree *node, t_env **env, t_btree **root)
{
	int	exitcode;

	if (!node)
		return (0);
	if (node->andor)
	{
		exitcode = pre_exec(node->left, env, root);
		if (exitcode == -1 || exitcode == -2 || g_g)
			return (exitcode);
		if (node->andor->content[0] == NODE_AND && exitcode == 0)
			exitcode = pre_exec(node->right, env, root);
		else if (node->andor->content[0] == NODE_OR && exitcode > 0)
			exitcode = pre_exec(node->right, env, root);
	}
	if (node->pipeline)
		exitcode = execute_pipeline(node->pipeline, env, root);
	return (exitcode);
}
