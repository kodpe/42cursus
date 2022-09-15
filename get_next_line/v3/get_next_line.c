/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 19:19:50 by sloquet           #+#    #+#             */
/*   Updated: 2022/09/08 16:16:39 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

char	*pull_line(char *stc)
{
	int	i;

	if (!ft_strchr(stc, '\n'))
		return (ft_strdup(stc));
	i = 0;
	while (stc[i] && stc[i] != '\n')
		i++;
	return (ft_substr(stc, 0, i + 1));
}

char	*clear_stc(char *stc)
{
	char	*new_stc;

	if (!ft_strchr(stc, '\n'))
		return (free(stc), NULL);
	new_stc = ft_strdup(ft_strchr(stc, '\n') + 1);
	free(stc);
	return (new_stc);
}

char	*ft_read(int fd, char *stc)
{
	char	*buffer;
	int		nb;
	char	*tmp;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free(stc), NULL);
	nb = 1;
	while (nb && !ft_strchr(stc, '\n'))
	{
		nb = read(fd, buffer, BUFFER_SIZE);
		if (nb == -1 || (nb == 0 && !stc[0]))
			return (free(buffer), free(stc), NULL);
		buffer[nb] = 0;
		if (nb == 0 && stc[0])
			return (free(buffer), stc);
		tmp = stc;
		stc = ft_strjoin(stc, buffer);
		free(tmp);
	}
	free(buffer);
	return (stc);
}

char	*get_next_line(int fd)
{
	static char	*stc;
	char		*line;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	if (!stc)
		stc = ft_strdup("");
	if (!stc)
		return (NULL);
	if (!ft_strchr(stc, '\n'))
		stc = ft_read(fd, stc);
	if (!stc)
		return (NULL);
	line = pull_line(stc);
	stc = clear_stc(stc);
	return (line);
}
