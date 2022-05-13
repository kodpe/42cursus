/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 05:55:51 by sloquet           #+#    #+#             */
/*   Updated: 2022/02/05 06:12:01 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*error_null(char *msg)
{
	if (PUSHSWAP_MSG)
		ft_printf("ERROR : %s\n", msg);
	ft_putsnl("Error");
	return (NULL);
}

void	*error_null_free_stack(t_stack *p, char *msg)
{
	if (PUSHSWAP_MSG)
		ft_printf("ERROR : %s\n", msg);
	ft_putsnl("Error");
	ft_stack_del(p);
	return (NULL);
}

void	error_exit(char *msg)
{
	if (PUSHSWAP_MSG)
		ft_printf("\e[33mERROR : %s\n\e[0m", msg);
	ft_putsnl("Error");
	exit(1);
}
