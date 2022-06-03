/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:54:44 by sloquet           #+#    #+#             */
/*   Updated: 2022/06/03 18:27:18 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 420 
# endif

# define FD_MAX 1024

# include <stdlib.h>
# include <unistd.h>

/**
 * get_next_line_utils.c
 */
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s, char *s2);
//char	*ft_strchr(const char *s, int c);
int		get_index(char *s);

/**
 * get_next_line.c
 */
char	*get_next_line(int fd);

#endif
