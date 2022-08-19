/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error_msg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:41:08 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/02 01:13:07 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	message_err_sous_shell(void)
{
	ft_putstr_fd(NAME, 2);
	ft_putsnl_fd(ERR_SS_SHELL, 2);
}

void	message_erreur(char *str, int show)
{
	if (!show)
		return ;
	ft_putstr_fd(NAME, 2);
	ft_putstr_fd(ERROR, 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("'\n", 2);
}

void	message_erreur_2(char *str)
{
	ft_putstr_fd(NAME, 2);
	ft_putstr_fd(ERROR, 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("'\n", 2);
}
