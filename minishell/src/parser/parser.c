/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:43:27 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/11 01:22:50 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_pipeline(t_btree **tree)
{
	return (get_pipeline(*tree, &valid_pipeline));
}

static int	check_cmd_redir(t_btree **tree)
{
	return (get_pipeline(*tree, &valid_cmd));
}

t_btree	*parser(t_token *tolkien, int *exitcode)
{
	t_btree	*tree;

	if (!tolkien)
	{
		*exitcode = ERR_MALLOC;
		return (NULL);
	}
	tree = NULL;
	*exitcode = check_one_input(tolkien);
	if (*exitcode)
		return (NULL);
	tree = btree_create(tolkien);
	if (!tree)
		return (NULL);
	*exitcode = check_pipeline(&tree);
	if (!*exitcode)
		*exitcode = check_cmd_redir(&tree);
	if (*exitcode)
		btree_destroy(&tree);
	return (tree);
}
