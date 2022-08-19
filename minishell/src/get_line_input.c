/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 23:46:45 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/30 10:09:06 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	only_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

static char	*non_tty(int *ctrld)
{
	char	*input;
	int		ret_gnl;

	ret_gnl = 0;
	input = get_next_line_2(0, &ret_gnl);
	get_next_line_2(-1, NULL);
	if (!input || ret_gnl)
	{
		*ctrld = 1;
		return (NULL);
	}
	return (input);
}

char	*get_line_input(int *ctrld)
{
	char	*input;

	if (isatty(0))
	{
		input = readline(MINISHELL_PROMPT);
		if (!input)
		{
			write(2, "exit\n", 5);
			*ctrld = 1;
			return (NULL);
		}
	}
	else
		return (non_tty(ctrld));
	if (!ft_strlen(input) || only_spaces(input))
	{
		free(input);
		return (NULL);
	}
	add_history(input);
	return (input);
}
