/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_last_dollar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:54:17 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/28 15:54:24 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*remove_last_dollar(char *s)
{
	char	*new;
	int		new_size;
	int		i;
	int		nb_dollars;

	i = ft_strlen(s) - 1;
	nb_dollars = 0;
	while (i >= 0)
	{
		if (s[i] != '$')
			break ;
		nb_dollars++;
		i--;
	}
	new_size = ft_strlen(s) + 1;
	if (nb_dollars % 2)
		new_size--;
	new = ft_strldup(s, new_size);
	free(s);
	return (new);
}

int	detect_last_dollar(t_token *t)
{
	if (t->name == T_WORD && t->next && t->next->name == T_ENTREQUOTE)
	{
		if (t->content[ft_strlen(t->content) - 1] == '$')
		{
			t->content = remove_last_dollar(t->content);
			if (!t->content)
				return (ERR_MALLOC);
		}
	}
	return (0);
}
