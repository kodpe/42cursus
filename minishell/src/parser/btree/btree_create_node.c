/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 23:04:07 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/10 23:04:12 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_btree	*btree_create_andor_node(t_token *andor)
{
	t_btree	*new;

	new = ft_calloc(sizeof(t_btree));
	if (!new)
		return (NULL);
	new->andor = andor;
	return (new);
}

t_btree	*btree_create_pipeline_leaf(t_token *pipeline)
{
	t_btree	*new;

	new = ft_calloc(sizeof(t_btree));
	if (!new)
		return (NULL);
	new->pipeline = pipeline;
	return (new);
}
