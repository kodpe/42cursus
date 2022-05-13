/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 10:49:04 by ggiquiau          #+#    #+#             */
/*   Updated: 2021/12/12 18:32:18 by ggiquiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H
# include <unistd.h>
# include <stdlib.h>

# define M 7000000
# define BUFFER_SIZE2 4096

typedef struct s_buf
{
	char	buf[BUFFER_SIZE2];
	int		len;
}			t_buf;

typedef struct s_list
{
	char			*key;
	char			*val;
	struct s_list	*next;
}					t_list;

void	found(t_buf *buf, const char *val);
void	notfound(t_buf *buf, const char *key, size_t n);

typedef unsigned long	t_ulong;

size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_bzero(void *s, size_t n);
int		get_next_line(int fd, char **line);
void	free_dict(t_list *dict);
int		exit_error(const char *s, t_list *dict, char *key, char *val);
void	add_key(t_list *l, char *key, char *val);
t_list	*new_list(char *key, char *val);
int		add_front(t_list **l, t_list *new, t_list *dict);

#endif
