/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_check_one_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 16:43:22 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/11 01:59:26 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_one_input(t_token *tolkien)
{
	int	ret;

	ret = valid_andor(tolkien);
	if (!ret)
		ret = valid_parenthesis(tolkien, 1);
	if (!ret)
		ret = content_is_valid(tolkien);
	if (ret)
		destroy_token_list(&tolkien);
	return (ret);
}
