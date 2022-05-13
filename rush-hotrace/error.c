/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:15:00 by ggiquiau          #+#    #+#             */
/*   Updated: 2021/12/12 18:32:14 by ggiquiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void	free_dict(t_list *dict)
{
	t_ulong	i;
	t_list	*tmp;
	t_list	*tmp2;

	i = 0;
	while (i < M)
	{
		free(dict[i].key);
		free(dict[i].val);
		tmp = dict[i].next;
		while (tmp)
		{
			free(tmp->key);
			free(tmp->val);
			tmp2 = tmp;
			tmp = tmp->next;
			free(tmp2);
		}
		i++;
	}
	free(dict);
}

int	exit_error(const char *s, t_list *dict, char *key, char *val)
{
	if (key)
		free(key);
	if (val)
		free(val);
	if (dict)
		free_dict(dict);
	write(2, s, ft_strlen(s));
	write(2, "\n", 1);
	get_next_line(0, 0);
	return (0);
}
