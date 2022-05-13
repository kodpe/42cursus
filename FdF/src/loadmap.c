/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:32:01 by sloquet           #+#    #+#             */
/*   Updated: 2022/03/19 03:10:25 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fdf.h"

// 1703-1502
static void	get_mapsize(t_map *m, char *file)
{
	char	**splited;
	char	*tmp;

	m->y_size = ft_filelen(file);
	tmp = ft_gnln(file, 1);
	if (!tmp)
		return ;
	splited = ft_split(tmp, ' ');
	free(tmp);
	if (!splited)
		return ;
	m->x_size = ft_arlen((const char **)splited);
	ft_arfree(splited);
}

// 1703-1922
static void	fill_z_map(t_map *m, char **splited, int y)
{
	int	x;

	if (y == 0)
	{
		m->z_min = ft_atoi(splited[0]);
		m->z_max = ft_atoi(splited[0]);
	}
	x = 0;
	while (splited[x] && x < m->x_size)
	{
		m->map[y][x] = ft_atoi(splited[x]);
		if (m->map[y][x] < m->z_min)
			m->z_min = m->map[y][x];
		if (m->map[y][x] > m->z_max)
			m->z_max = m->map[y][x];
		x++;
	}
	ft_arfree(splited);
	if (y + 1 == m->y_size)
		m->z_size = ft_distance_btw_values(m->z_max, m->z_min);
}

// 1703-1905
static int	get_numbers(t_map *m, char *file)
{
	char	**splited;
	char	*tmp;
	int		fd;
	int		y;

	fd = open(file, O_RDONLY);
	if (0 > fd)
		return (error_getnbr(fd, -1));
	tmp = NULL;
	y = 0;
	while (y < m->y_size)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			return (error_getnbr(fd, -1));
		splited = ft_split(tmp, ' ');
		free(tmp);
		if (!splited)
			return (error_getnbr(fd, -1));
		fill_z_map(m, splited, y);
		y++;
	}
	ft_close_gnl(fd);
	close(fd);
	return (0);
}

// 1703-1911
t_map	*loadmap(char *file)
{
	t_map	*m;

	m = malloc(sizeof(t_map));
	if (!m)
		return (NULL);
	m->x_size = 0;
	m->y_size = 0;
	m->z_size = 0;
	m->z_min = 0;
	m->z_max = 0;
	get_mapsize(m, file);
	ft_printf("loadmap()           : %s (%d,%d)\n", file, m->x_size, m->y_size);
	if (m->x_size <= 0 || m->y_size <= 0)
	{
		free(m);
		return (NULL);
	}
	m->map = ft_new_iitab(m->x_size, m->y_size, 0);
	if (!m->map)
		return (free_map(m));
	if (0 > get_numbers(m, file))
		return (free_map(m));
	return (m);
}
