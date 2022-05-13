/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:14:00 by ggiquiau          #+#    #+#             */
/*   Updated: 2021/12/12 18:23:19 by ggiquiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void	add_key(t_list *l, char *key, char *val)
{
	l->key = key;
	l->val = val;
}

t_list	*new_list(char *key, char *val)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->key = key;
	new->val = val;
	new->next = NULL;
	return (new);
}

int	add_front(t_list **l, t_list *new, t_list *dict)
{
	if (!new)
		return (exit_error("add_front malloc error", dict, 0, 0));
	new->next = *l;
	*l = new;
	return (1);
}
