/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:19:58 by sloquet           #+#    #+#             */
/*   Updated: 2021/11/26 15:58:16 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Adds the element ’new’ at the end of the list.
 */

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*zlst;

	if (!*alst)
	{
		*alst = new;
		return ;
	}
	zlst = ft_lstlast(*alst);
	zlst->next = new;
}
