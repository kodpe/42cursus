/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 11:32:04 by ggiquiau          #+#    #+#             */
/*   Updated: 2021/12/11 11:10:39 by ggiquiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	set_line(char **readstr, t_listfd *fd_rest, char **line, long i)
{
	char	*tmp;

	tmp = ft_substr(*readstr, 0, i);
	*line = ft_strjoin(fd_rest->rest, tmp);
	free(tmp);
	free(fd_rest->rest);
	fd_rest->rest = ft_strdup(*readstr + i + 1);
	free(*readstr);
	*readstr = NULL;
	if (*line && fd_rest->rest)
		return (1);
	else
		return (-1);
}

int	ft_readfile(char **readstr, t_listfd *fd_rest, char **line, int fd)
{
	char	buf[BUFFER_SIZE + 1];
	long	i;
	int		ret;

	ret = read(fd, buf, BUFFER_SIZE);
	while (ret > 0)
	{
		buf[ret] = '\0';
		ft_str_realloc(readstr, ft_strjoin(*readstr, buf));
		if (!*readstr)
			return (-1);
		i = chrindex(*readstr, '\n');
		if (i != -1)
			return (set_line(readstr, fd_rest, line, i));
		ret = read(fd, buf, BUFFER_SIZE);
	}
	return (ret);
}

void	ft_free(t_listfd *fd_rest, t_listfd **fds, char *readstr)
{
	t_listfd	*tmp;

	tmp = *fds;
	free(readstr);
	if (fd_rest)
	{
		if ((*fds)->fd != fd_rest->fd)
		{
			while (tmp->next->fd != fd_rest->fd)
				tmp = tmp->next;
			tmp->next = tmp->next->next;
		}
		free(fd_rest->rest);
		fd_rest->rest = NULL;
		if ((*fds)->fd == fd_rest->fd)
			*fds = (*fds)->next;
		free(fd_rest);
	}
}

t_listfd	*search_fd(t_listfd **fds, int fd)
{
	t_listfd	*tmp;

	tmp = *fds;
	if (!(*fds))
	{
		*fds = (t_listfd *)malloc(sizeof(t_listfd));
		if (!*fds)
			return (NULL);
		(*fds)->fd = fd;
		(*fds)->next = NULL;
		(*fds)->rest = NULL;
		return (*fds);
	}
	while (tmp->fd != fd && tmp->next)
		tmp = tmp->next;
	if (tmp->fd == fd)
		return (tmp);
	tmp->next = (t_listfd *)malloc(sizeof(t_listfd));
	if (!tmp->next)
		return (NULL);
	tmp->next->fd = fd;
	tmp->next->next = NULL;
	tmp->next->rest = NULL;
	return (tmp->next);
}

int	get_next_line(int fd, char **line)
{
	t_listfd		*fd_rest;
	long			i;
	char			*readstr;
	static t_listfd	*fds;

	readstr = ft_strdup("");
	fd_rest = search_fd(&fds, fd);
	if (!readstr || !fd_rest || !line || BUFFER_SIZE < 1)
		i = -1;
	else
	{
		i = search_rest(fd_rest, line, readstr);
		if (i == -1)
			i = ft_readfile(&readstr, fd_rest, line, fd);
		if (i == 0)
		{
			*line = ft_strjoin(fd_rest->rest, readstr);
			i = -1 * (*line == NULL);
		}
	}
	if (i <= 0)
		ft_free(fd_rest, &fds, readstr);
	if (i == -1 && line)
		*line = NULL;
	return ((int)i);
}
