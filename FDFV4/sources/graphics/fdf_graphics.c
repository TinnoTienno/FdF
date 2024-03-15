/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_graphics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:48:37 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/13 17:21:55 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_graphics(t_vars *vars, char *str)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		fdf_error(vars, "Error in MLX_INIT function\n");
	vars->win = mlx_new_window(vars->mlx, FDF_WINDOW_WIDTH, FDF_WINDOW_HEIGHT, str);
	if (!vars->win)
		fdf_error(vars, "Error in MLX_NEW_WINDOW function\n");
	vars->img.img = mlx_new_image(vars->mlx, FDF_WINDOW_WIDTH - FDF_WINDOW_BORDER, FDF_WINDOW_HEIGHT - FDF_WINDOW_BORDER);
	if (!vars->img.img)
		fdf_error(vars, "Error in MLX_NEW_IMAGE function\n");FDF_WINDOW_WIDTH, FDF_WINDOW_HEIGHT
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel, &vars->img.line_length,
								&vars->img.endian);
	fdf_graphics_scale(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, FDF_WINDOW_BORDER / 2, FDF_WINDOW_BORDER / 2);
	mlx_hook(vars->win, 2, 1L<<0, fdf_graphics_keypress, vars);
	mlx_loop(vars->mlx);
	fdf_error(vars, "");
}
