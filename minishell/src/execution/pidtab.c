/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pidtab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:10:00 by chsimon           #+#    #+#             */
/*   Updated: 2022/07/28 11:57:51 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

pid_t	*create_pidtab(size_t nb_fork)
{
	return ((pid_t *)ft_calloc(sizeof(pid_t) * nb_fork));
}

void	wait_all_child(pid_t *pid, int i)
{
	while (i >= 0)
	{
		if (0 > waitpid(pid[i], NULL, 0))
			perror("exec: waitpid");
		i--;
	}
	free(pid);
}
