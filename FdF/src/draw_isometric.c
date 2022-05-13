/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_isometric.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 04:27:44 by sloquet           #+#    #+#             */
/*   Updated: 2022/04/09 04:25:43 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	set_zoom(t_fdf *f, t_map *m)
{
	int	y;
	int	xr;
	int	xl;

	m->zoom = 16;
	while (1)
	{
		if (m->z_size > 200)
			m->zoom = 1;
		y = m->zoom * (m->x_size + m->y_size - 2);
		xr = m->zoom * (m->x_size - 1) * 2;
		xl = m->zoom * (1 - m->y_size) * 2;
		m->origin.x = f->center.x - (xr + xl) / 2;
		m->origin.y = f->center.y - (y / 2);
		if (m->zoom == 1)
			break ;
		if (m->origin.y + y < f->win_y && m->origin.x + xr < f->win_x)
			break ;
		m->zoom--;
	}
}

static int	iso_x(int x, int y, t_map *m)
{
	return (m->origin.x + m->zoom * (x - y) * 2);
}

static int	iso_y(int x, int y, t_map *m)
{
	return (m->origin.y + m->zoom * (x + y) - m->map[y][x] * 2);
}

static void	convert_iso(t_fdf *f, t_map *m, int x, int y)
{
	t_line	line;

	line.x0 = iso_x(x, y, m);
	line.y0 = iso_y(x, y, m);
	line.z0 = m->map[y][x];
	line.color0 = getcolor(m, line.z0);
	line.color_step = 0;
	if (x + 1 < m->x_size)
	{
		line.x1 = iso_x(x + 1, y, m);
		line.y1 = iso_y(x + 1, y, m);
		line.z1 = m->map[y][x + 1];
		line.color1 = getcolor(m, line.z1);
		line.len = distance_cart(&line);
		drawline(f, line);
	}
	if (y + 1 < m->y_size)
	{
		line.x1 = iso_x(x, y + 1, m);
		line.y1 = iso_y(x, y + 1, m);
		line.z1 = m->map[y + 1][x];
		line.color1 = getcolor(m, line.z1);
		line.len = distance_cart(&line);
		drawline(f, line);
	}
}

void	draw_isometric(t_fdf *f, t_map *m)
{
	int	y;
	int	x;

	set_zoom(f, m);
	y = 0;
	while (y < m->y_size)
	{
		x = 0;
		while (x < m->x_size)
		{
			convert_iso(f, m, x, y);
			x++;
		}
		y++;
	}
}
