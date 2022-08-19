/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 13:29:43 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/29 16:33:33 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "minishell.h"

#define ERR_WR_ECHO "minimichel: echo: write error"

static int	bt_skip_flags_n(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_strlen(argv[i]) < 2)
			break ;
		if (argv[i][0] != '-' || argv[i][1] != 'n')
			break ;
		if (!ft_contains_only('n', &argv[i][1]))
			break ;
		i++;
	}
	return (i);
}

int	builtin_echo(char **argv)
{
	bool	newline;
	size_t	start;
	size_t	i;

	newline = 1;
	start = bt_skip_flags_n(++argv);
	if (start > 0)
		newline = 0;
	i = start;
	while (argv[i])
	{
		if (sc_write(1, argv[i], ERR_WR_ECHO))
			return (1);
		if (argv[i + 1])
			if (sc_write(1, " ", ERR_WR_ECHO))
				return (1);
		i++;
	}
	if (newline && sc_write(1, "\n", ERR_WR_ECHO))
		return (1);
	return (0);
}

/*
int	main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)envp;
	int	exitcode = builtin_echo(++av);
	return (exitcode);
}
*/
