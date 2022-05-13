/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 04:11:26 by sloquet           #+#    #+#             */
/*   Updated: 2022/04/09 04:22:11 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// 1503-1520
void	fdf_destroy(t_fdf *f, int code, char *msg)
{
	ft_printf("fdf_destroy()       : %s(%d)\n", msg, code);
	if (f->img_id)
		mlx_destroy_image(f->mlx_id, f->img_id);
	if (f->win)
		mlx_destroy_window(f->mlx_id, f->win);
	if (f->mlx_id)
		mlx_destroy_display(f->mlx_id);
	free(f->mlx_id);
	if (code > 30)
		error_exit(code, msg);
	exit(code);
}

// 1703-1413
void	*free_map(t_map *m)
{
	if (m->map)
		ft_iifree(m->map, m->y_size);
	free(m);
	m = NULL;
	return (NULL);
}

// 0904-0703
int	distance_cart(t_line *a)
{
	int	dx;
	int	dy;

	dx = ft_distance_btw_values(a->x0, a->x1);
	dy = ft_distance_btw_values(a->y0, a->y1);
	return (sqrt(dx * dx + dy * dy));
}

//	0904-0718
t_uint	getcolor(t_map *m, int z)
{
	double	color;

	color = (double)(z - m->z_min) / (double)(m->z_max - m->z_min) * 255;
	return (COLOR + (t_uint)color);
}
