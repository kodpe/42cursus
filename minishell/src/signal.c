/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:56:22 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/29 18:51:10 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//utiliser istty pour savoir si on est dans un fork ou non 

void	sighandler(int signum)
{
	if (signum == SIGINT)
	{
		write(2, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_g = 1;
	}
}

void	sig_heredoc(int signum)
{
	if (signum == SIGINT)
	{
		g_g = 1;
		close(0);
	}
}

void	sig_exec(int signum)
{
	if (signum == SIGINT)
		write(2, "", 1);
}

void	sig_child(int signum)
{
	(void)signum;
}
