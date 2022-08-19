/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_isname.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 21:32:02 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/26 21:32:12 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	env_isname(char *name)
{
	int	i;

	if (!ft_strlen(name) || isdigit(name[0]))
		return (false);
	i = 0;
	while (name[i])
	{
		if (!ft_isalnum(name[i]) && name[i] != '_')
			return (false);
		i++;
	}
	return (true);
}
