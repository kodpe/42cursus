/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_convert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 03:09:42 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/11 19:01:41 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*token_convert(char **splited)
{
	t_token	*new;
	int		i;

	if (!splited)
		return (NULL);
	new = NULL;
	i = 0;
	while (splited[i])
	{
		if (add_back(&new, new_token(T_WORD, splited[i], 0)))
		{
			ft_arfree(splited);
			return (NULL);
		}
		if (splited[i + 1] && add_back(&new, new_token(T_WHITESPACE, " ", 0)))
		{
			ft_arfree(splited);
			return (NULL);
		}
		i++;
	}
	ft_arfree(splited);
	return (new);
}
