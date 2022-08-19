/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:47:10 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/01 18:27:45 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	token_valid(t_token *lst, t_token *to_find)
{
	while (lst)
	{
		if (lst == to_find)
			return (1);
		lst = lst->next;
	}
	return (0);
}
