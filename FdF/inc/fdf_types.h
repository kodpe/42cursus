/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_types.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 04:49:37 by sloquet           #+#    #+#             */
/*   Updated: 2022/04/09 04:19:46 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_TYPES_H
# define FDF_TYPES_H 

typedef unsigned int	t_uint;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}		t_point;

typedef struct s_line
{
	int		x0;
	int		y0;
	int		z0;
	int		x1;
	int		y1;
	int		z1;
	int		x_slope;
	int		y_slope;
	int		x_delta;
	int		y_delta;
	t_uint	color0;
	t_uint	color1;
	int		color_step;
	int		len;
}		t_line;

typedef struct s_fdf
{
	void	*mlx_id;
	void	*win;
	int		win_x;
	int		win_y;
	void	*img_id;
	char	*img_addr;
	int		img_endian;
	int		bits_per_pixel;
	int		line_length;
	t_point	center;
}			t_fdf;

typedef struct s_map
{
	int		**map;
	int		x_size;
	int		y_size;
	int		z_size;
	int		z_min;
	int		z_max;
	int		zoom;
	t_point	origin;
}		t_map;

#endif /*  FDF_TYPES_H */
