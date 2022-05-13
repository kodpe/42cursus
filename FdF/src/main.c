/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 10:49:45 by sloquet           #+#    #+#             */
/*   Updated: 2022/03/19 04:36:25 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// 1503-1551
int	exit_cross(t_fdf *f)
{
	fdf_destroy(f, 0, "exit_cross");
	return (0);
}

// 1503-1552
int	key_press(int keycode, t_fdf *f)
{
	ft_printf("key_press()         : %d\n", keycode);
	if (keycode == 0xff1b)
		fdf_destroy(f, 0, "exit_escape");
	return (0);
}

int	main(int ac, char **av)
{
	t_fdf	f;
	t_map	*m;

	fdf_init_mlx(&f, ac);
	m = loadmap(av[1]);
	if (!m)
		fdf_destroy(&f, 35, "loadmap()");
	draw_isometric(&f, m);
	free_map(m);
	mlx_put_image_to_window(f.mlx_id, f.win, f.img_id, 0, 0);
	mlx_hook(f.win, 2, 1L << 0, &key_press, &f);
	mlx_hook(f.win, 17, 0, &exit_cross, &f);
	mlx_loop(f.mlx_id);
	fdf_destroy(&f, 36, "invalid exit");
}
