/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_graphics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:48:17 by eschussl          #+#    #+#             */
/*   Updated: 2024/04/05 00:35:48 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_graphics(t_main *main)
{
	fdf_image_z_init(main);
	main->mlx = mlx_init();
	if (!main->mlx)
		fdf_error(main, "Error in mlx_init function : Malloc\n");
	main->win = mlx_new_window(main->mlx, main->finfo.w_width, main->finfo.w_height, main->finfo.filename);
	if (!main->win)
		fdf_error(main, "Error in mlx_new_window function : Malloc\n");
	fdf_image_init(main);
	mlx_mouse_hook(main->win, fdf_mouse_scroll, main);
	mlx_hook(main->win, 2, 1L<<0, fdf_hooks_keypress, main);
	mlx_loop_hook(main->mlx, fdf_push_loop, main);
	mlx_loop(main->mlx);
}