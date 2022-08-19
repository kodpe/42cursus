/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_expander_heredoc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:50:16 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/28 16:12:11 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_expander_here_doc(t_token **t)
{
	*t = (*t)->next;
	if (*t && (*t)->name == T_WHITESPACE)
		*t = (*t)->next;
	while (*t && (*t)->name != T_WHITESPACE)
	{
		if (detect_last_dollar(*t))
			return (ERR_MALLOC);
		*t = (*t)->next;
	}
	return (0);
}
