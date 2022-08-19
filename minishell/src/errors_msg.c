/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_msg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 12:15:15 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/29 21:37:35 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	err_msg(char *msg)
{
	sc_write(2, msg, WRITE_ERROR);
}

int	err_msg_2(char *name, char *msg)
{
	char	*join;

	join = ft_strjoin(name, msg);
	if (!join)
		return (ERR_MALLOC);
	sc_write(2, join, WRITE_ERROR);
	free(join);
	return (0);
}

int	err_msg_3(char *title, char *name, char *msg)
{
	char	*join;

	join = ft_strjointri(title, name, msg);
	if (!join)
		return (ERR_MALLOC);
	sc_write(2, join, WRITE_ERROR);
	free(join);
	return (0);
}

int	err_msg_3_space_nl(char *title, char *name, char *msg)
{
	char	*join;
	char	*tmp;

	tmp = ft_strjointri(title, name, " ");
	if (!tmp)
		return (ERR_MALLOC);
	join = ft_strjointri(tmp, msg, "\n");
	free (tmp);
	if (!join)
		return (ERR_MALLOC);
	sc_write(2, join, WRITE_ERROR);
	free(join);
	return (0);
}
