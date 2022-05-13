/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 00:26:01 by sloquet           #+#    #+#             */
/*   Updated: 2022/04/09 04:40:55 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H 

# include <math.h>
# include "libft.h"
# include "mlx.h"
# include "fdf_types.h"

# define FDF_DEBUG 0
# define COLOR 0x00FF00
# define KEY_ESC 0xff1b

void	fdf_init_mlx(t_fdf *f, int ac);
t_map	*loadmap(char *file);
void	draw_isometric(t_fdf *f, t_map *m);
void	drawline(t_fdf *f, t_line a);

/**
 * 		utils.c
 */
void	fdf_destroy(t_fdf *f, int code, char *msg);
void	*free_map(t_map *m);
int		distance_cart(t_line *a);
t_uint	getcolor(t_map *m, int z);

/**
 * 		error.c
 */
int		error_exit(int code, char *msg);
void	error_line(const t_line *a);
int		error_getnbr(int fd, int n);

#endif /*  FDF_H */
