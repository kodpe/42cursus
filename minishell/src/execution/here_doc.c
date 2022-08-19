/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:58:33 by chsimon           #+#    #+#             */
/*   Updated: 2022/07/29 05:20:49 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_tmp_name(int *i)
{
	char	*str;
	char	*nb;

	nb = ft_itoa(*i);
	if (!nb)
	{
		*i = -2;
		return (NULL);
	}
	str = ft_strjointri("/tmp/", ".here_doc_minishell_t_as_vu_", nb);
	free(nb);
	if (!str)
	{
		*i = -2;
		return (NULL);
	}
	if (access(str, F_OK) == -1)
	{
		if (errno == ENOENT)
			return (str);
		perror("get_tmp_file");
		*i = -2;
	}
	free (str);
	return (NULL);
}

char	*get_tmp_file(void)
{
	char	*str;
	int		i;

	i = 0;
	while (i < INT_MAX && i >= 0)
	{
		str = get_tmp_name(&i);
		if (str)
			break ;
		i++;
	}
	if (i == INT_MAX)
	{
		ft_dprintf(2, "How did you do that ?");
		return (NULL);
	}
	return (str);
}

int	error_eof_heredoc(char *eof)
{
	char	*str;

	str = ft_strjointri("msh: warning: here-document \
	delimited by end-of-file (wanted `", eof, "')\n");
	if (!str)
		return (ERR_MALLOC);
	ft_putstr_fd(str, 2);
	free(str);
	return (0);
}

int	fill_here_doc(int fd, char *eof, t_env *env, int expanded)
{
	char	*str;
	int		len;

	while (1)
	{
		str = readline("> ");
		if (g_g)
			break ;
		if (!str)
			return (error_eof_heredoc(eof));
		len = ft_strlen(eof);
		if (!ft_strncmp(str, eof, len))
			break ;
		if (!expanded)
		{	
			str = expander(str, env);
			if (!str)
				return (ERR_MALLOC);
		}
		ft_putsnl_fd(str, fd);
		free(str);
	}
	if (str)
		free(str);
	return (0);
}

// int	main(void)
// {
// 	int	fd;
// 	int	fd2;
// 	int	fd3;
// 	char *str;

// 	fd = open("/tmp", __O_TMPFILE | O_RDWR | O_TRUNC, 0644);
// 	fd2 = open("a",  O_CREAT | O_RDWR | O_TRUNC, 0644);
// 	fd3 = dup(fd);
// 		ft_dprintf(2, "value of fd %d\n", fd);
// 	if (fd == -1)
// 	{
// 		perror("mini-mishell: open_redir_in");
// 		return (ERR_REDIR);
// 	}
// 		ft_dprintf(2, "value of fd2 %d\n", fd2);
// 	if (fd2 == -1)
// 	{
// 		perror("mini-mishell: open_redir_in");
// 		return (ERR_REDIR);
// 	}
// 		ft_dprintf(2, "value of fd3 %d\n", fd3);
// 	if (fd3 == -1)
// 	{
// 		perror("mini-mishell: open_redir_in");
// 		return (ERR_REDIR);
// 	}
// 	manage_heredoc(fd, fd2, "eof");
// 	close(fd2);
// 	fd2 = open("a", O_RDONLY);
// 	ft_putstr_fd("=== TEST DANS a ===\n", 2);
// 	while (1)
// 	{
// 		str = get_next_line(fd2);
// 		if (!str)
// 			break;
// 		ft_putstr_fd(str, 1);
// 	}
// 	fd = open("/tmp", __O_TMPFILE | O_RDWR | O_TRUNC, 0644);
// 	ft_putstr_fd("=== TEST DANS TMP_FILE ===\n", 2);
// 	while (1)
// 	{
// 		str = get_next_line(fd);
// 		if (!str)
// 			break;
// 		ft_putstr_fd(str, 1);
// 	}
// 	close(fd);
// 	close(fd2);
// 	close(fd3);
// }
