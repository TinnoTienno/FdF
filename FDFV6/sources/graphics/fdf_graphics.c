/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_graphics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:59:51 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/15 21:54:51 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <X11/X.h>

void	fdf_graphics(t_main *main)
{
	main->mlx = mlx_init();
	if (!main->mlx)
		fdf_error(main, "Error in mlx_init : Malloc\n");
	main->win = mlx_new_window(main->mlx, FDF_WINDOW_WIDTH, FDF_WINDOW_HEIGHT, main->arg);
	if (!main->win)
		fdf_error(main, "Error in mlx_new_window function : Malloc\n");
	main->image.img = mlx_new_image(main->mlx, FDF_WINDOW_WIDTH, FDF_WINDOW_HEIGHT);
	if (!main->image.img)
		fdf_error(main, "Error in mlx_new_image function : Malloc\n");
	// printf("%p\n", main->image.img);
	main->image.addr = mlx_get_data_addr(main->image.img, &main->image.bits_per_pixel, &main->image.line_length, &main->image.endian);
	mlx_mouse_hook(main->win, fdf_mouse_scroll, main);
	fdf_scale_edit(main);
	fdf_set_points(main);
	fdf_draw_points(main);
	mlx_put_image_to_window(main->mlx, main->win, main->image.img, 0, 0);
	
	mlx_hook(main->win, 2, 1L<<0, fdf_graphics_keypress, main);
	mlx_loop(main->mlx);
}
