/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:25:47 by sloquet           #+#    #+#             */
/*   Updated: 2022/04/09 04:45:13 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// 1503-1002
static void	pixel(t_fdf *f, int x, int y, unsigned int color)
{
	char			*dst;
	int				offset;

	offset = y * f->line_length + x * (f->bits_per_pixel / 8);
	dst = f->img_addr + offset;
	*(unsigned int *)dst = color;
}

// 0904-0823
static void	draw_pixelcolor(t_fdf *f, t_line *line, int step)
{
	unsigned int	color;

	color = line->color0;
	if (line->z0 < line->z1)
		color = line->color0 + step * line->color_step;
	if (line->z0 > line->z1)
		color = line->color0 - step * line->color_step;
	pixel(f, line->x0, line->y0, color);
}

// 1603-1822
static void	bresenham_line(t_fdf *f, t_line *a)
{
	int	error;
	int	step;

	step = 0;
	error = a->x_delta + a->y_delta;
	while (1)
	{
		draw_pixelcolor(f, a, step++);
		if (a->x0 == a->x1 && a->y0 == a->y1)
			break ;
		if (2 * error >= a->y_delta)
		{
			if (a->x0 == a->x1)
				break ;
			error += a->y_delta;
			a->x0 += a->x_slope;
		}
		if (2 * error <= a->x_delta)
		{
			if (a->y0 == a->y1)
				break ;
			error += a->x_delta;
			a->y0 += a->y_slope;
		}
	}
}

// 1703-1104
void	drawline(t_fdf *f, t_line a)
{
	if (a.x0 < 0 || a.x0 >= f->win_x || a.y0 < 0 || a.y0 >= f->win_y)
		return (error_line(&a));
	if (a.x1 < 0 || a.x1 >= f->win_x || a.y1 < 0 || a.y1 >= f->win_y)
		return (error_line(&a));
	if (a.x0 < a.x1)
		a.x_slope = 1;
	else
		a.x_slope = -1;
	if (a.y0 < a.y1)
		a.y_slope = 1;
	else
		a.y_slope = -1;
	a.x_delta = ft_abs(a.x1 - a.x0);
	a.y_delta = -ft_abs(a.y1 - a.y0);
	if (a.len > 0 && a.len < 256)
	{
		if (a.color0 < a.color1)
			a.color_step = (a.color1 - a.color0) / a.len;
		if (a.color0 > a.color1)
			a.color_step = (a.color0 - a.color1) / a.len;
	}
	bresenham_line(f, &a);
}
