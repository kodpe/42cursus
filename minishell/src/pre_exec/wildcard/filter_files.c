/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 12:44:45 by chsimon           #+#    #+#             */
/*   Updated: 2022/07/07 12:11:26 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_if_filter_all(t_token *file)
{
	int	i;

	i = 0;
	while (file)
	{
		if (file->name != T_DEL)
			i++;
		file = file->next;
	}
	return (i);
}

t_token	*filter_files(t_token *file, char *s)
{
	t_token	*copy;

	if (check_if_filter_all(file))
		copy = copy_lst_del_w(file);
	else
		copy = new_token(T_WORD, s, ft_strlen(s));
	destroy_token_list(&file);
	if (!copy)
		return (NULL);
	return (copy);
}
