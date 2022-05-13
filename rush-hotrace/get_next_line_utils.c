/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 15:40:14 by ggiquiau          #+#    #+#             */
/*   Updated: 2021/11/29 17:32:04 by ggiquiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

long	chrindex(char *str, char c)
{
	int	i;

	i = -1;
	if (!str)
		return (-1);
	while (str[++i])
		if (str[i] == c)
			return (i);
	return (-1);
}

void	ft_str_realloc(char **str, char *new)
{
	free(*str);
	*str = new;
}

int	search_rest(t_listfd *fd_rest, char **line, char *readstr)
{
	long	i;

	i = chrindex(fd_rest->rest, '\n');
	if (i != -1)
	{
		*line = ft_substr(fd_rest->rest, 0, i);
		ft_str_realloc(&(fd_rest->rest), ft_strdup(fd_rest->rest + i + 1));
		i = 1;
		if (!*line || !(fd_rest->rest))
			i = -2;
		free(readstr);
		readstr = NULL;
	}
	return (i);
}
