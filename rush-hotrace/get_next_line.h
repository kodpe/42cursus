/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 11:41:52 by ggiquiau          #+#    #+#             */
/*   Updated: 2021/12/12 15:35:24 by ggiquiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "hotrace.h"
# define BUFFER_SIZE 64

typedef struct s_listfd
{
	int				fd;
	char			*rest;
	struct s_listfd	*next;
}				t_listfd;
int				get_next_line(int fd, char **line);
int				ft_readfile(char **readstr, t_listfd *f, char **line, int fd);
long			chrindex(char *str, char c);
void			ft_free(t_listfd *fd_rest, t_listfd **fds, char *readstr);
void			ft_str_realloc(char **str, char *new);
t_listfd		*search_fd(t_listfd **fds, int fd);
int				search_rest(t_listfd *fd_rest, char **line, char *readstr);
#endif
