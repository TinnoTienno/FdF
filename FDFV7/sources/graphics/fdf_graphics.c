/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_graphics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:39:52 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/25 17:30:18 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_graphics(t_main *main)
{
	main->mlx = mlx_init();
	if (!main->mlx)
		fdf_error(main, "Error in mlx_init function : Malloc\n");
	main->win = mlx_new_window(main->mlx, main->file_info.window_width, main->file_info.window_height, main->file_info.filename);
	if (!main->win)
		fdf_error(main, "Error in mlx_new_window function : Malloc\n");
	fdf_image_init(main);
	fdf_draw_points(main);
	mlx_hook(main->win, 2, 1L<<0, fdf_graphics_keypress, main);
	mlx_mouse_hook(main->win, fdf_mouse_scroll, main);
	mlx_loop_hook(main->mlx, fdf_push_loop, main);
	mlx_loop(main->mlx);
}