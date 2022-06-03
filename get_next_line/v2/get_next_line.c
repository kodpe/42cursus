/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:53:59 by sloquet           #+#    #+#             */
/*   Updated: 2022/06/03 18:23:20 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *save)
{
	int		i;
	char	*buff;

	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	i = 1;
	while (i > 0 && get_index(save) == -1)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i < 1 && !save[0])
		{
			free(buff);
			free(save);
			return (NULL);
		}
		buff[i] = 0;
		if (i < 1 && save[0])
		{
			free(buff);
			return (save);
		}
		save = ft_strjoin(save, buff);
	}
	free(buff);
	return (save);
}

char	*ft_pull(char *save)
{
	char	*line;

	if (get_index(save) == -1)
		line = (ft_substr(save, 0, ft_strlen(save)));
	else
		line = (ft_substr(save, 0, get_index(save) + 1));
	return (line);
}

char	*ft_update_save(char *save)
{
	char	*new_save;

	if (get_index(save) == -1)
	{
		free(save);
		save = NULL;
		return (NULL);
	}
	new_save = ft_strdup(&save[get_index(save) + 1]);
	free(save);
	return (new_save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (BUFFER_SIZE < 1 || fd < 0 || fd > FD_MAX)
		return (NULL);
	if (!save)
	{
		save = malloc(1);
		if (!save)
			return (NULL);
		save[0] = 0;
	}
	if (get_index(save) == -1)
	{
		save = ft_read(fd, save);
		if (!save)
			return (NULL);
	}
	line = ft_pull(save);
	save = ft_update_save(save);
	return (line);
}
