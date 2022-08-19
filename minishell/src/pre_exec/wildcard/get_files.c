/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 18:43:30 by chsimon           #+#    #+#             */
/*   Updated: 2022/07/27 16:52:38 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

DIR	*get_dirp(void)
{
	char			*path;
	DIR				*dirp;

	path = getcwd(NULL, 0);
	if (!path)
	{
		perror("wildcard.get_files.getcwd");
		return (NULL);
	}
	dirp = opendir(path);
	free(path);
	if (!dirp)
	{
		perror("wildcard.get_files.opendir");
		return (NULL);
	}
	return (dirp);
}

int	directory_list(t_token **file, DIR *dirp)
{
	struct dirent	*directo;

	errno = 0;
	while (dirp)
	{
		directo = readdir(dirp);
		if (!directo)
			break ;
		if (add_back(file,
				new_token(T_WORD, directo->d_name, ft_strlen(directo->d_name))))
		{
			if (closedir(dirp))
				perror("wildcard.get_files.closedir_failed readdir");
			destroy_token_list(file);
			return (ERR_MALLOC);
		}
	}
	if (errno)
	{
		perror("wildcard.get_files.readir");
		destroy_token_list(file);
		file = NULL;
	}
	return (0);
}

int	get_files(t_token **file)
{
	DIR	*dirp;

	dirp = get_dirp();
	if (!dirp)
		return (0);
	if (directory_list(file, dirp))
		return (ERR_MALLOC);
	if (closedir(dirp))
		perror("wildcard.get_files.closedir");
	sort_token_content(file);
	return (0);
}
