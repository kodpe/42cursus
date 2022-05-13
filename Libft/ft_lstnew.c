/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 19:57:57 by sloquet           #+#    #+#             */
/*   Updated: 2021/11/28 23:17:34 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Allocates (with malloc(3)) and returns a new element.
 * The variable ’content’ is initialized
 * with the value of the parameter ’content’.
 * The variable ’next’ is initialized to NULL.
 */

t_list	*ft_lstnew(void *content)
{
	t_list	*e;

	e = (t_list *)malloc(sizeof(t_list));
	if (!e)
		return (NULL);
	e->content = content;
	e->next = NULL;
	return (e);
}
