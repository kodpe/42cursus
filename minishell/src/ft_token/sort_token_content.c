/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_token_content.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:32:39 by chsimon           #+#    #+#             */
/*   Updated: 2022/07/27 15:49:18 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	swap_str(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

void	sort_token_content(t_token	**file)
{
	t_token	*try;
	t_token	*cmp;

	cmp = *file;
	while (cmp)
	{
		try = cmp->next;
		while (try)
		{
			if (ft_strcmp_to_lower(cmp->content, try->content) > 0)
				swap_str(&cmp->content, &try->content);
			try = try->next;
		}
		cmp = cmp->next;
	}
}
