/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_dictionary.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 22:25:41 by sloquet           #+#    #+#             */
/*   Updated: 2021/08/22 23:13:57 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

int	ft_count_lines(char *str)
{
	int	nbr_lines;

	nbr_lines = 0;
	while (*str)
	{
		if (*str == '\n' && *(str + 1) != '\n')
			nbr_lines++;
		str++;
	}
	return (nbr_lines - 1);
}

int	ft_get_size_of_file(char *dict_name)
{
	int		file;
	int		size;
	int		nbr_octets;
	char	car;

	file = open(dict_name, O_RDONLY, S_IRUSR | S_IRGRP | S_IROTH);
	if (file == -1)
		return (0);
	car = 0;
	size = 0;
	nbr_octets = 1;
	while (nbr_octets != 0)
	{
		nbr_octets = read(file, &car, 1);
		size++;
	}
	close(file);
	return (size);
}

char	*ft_create_buffer(char *dict_name, int size)
{
	int		fd;
	int		i;
	int		n;
	char	*buffer;

	buffer = malloc(sizeof(*buffer) * (size + 1));
	if (buffer == NULL)
		return (NULL);
	fd = open(dict_name, O_RDONLY, S_IRUSR | S_IRGRP | S_IROTH);
	if (fd == -1)
		return (0);
	i = 0;
	n = 1;
	while (n != 0)
	{
		n = read(fd, buffer + i, 1);
		i++;
	}
	close(fd);
	buffer[--i] = '\0';
	return (buffer);
}
