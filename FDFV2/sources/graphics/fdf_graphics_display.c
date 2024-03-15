/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_graphics_display.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:12:49 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/01 18:27:02 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_graphics_display(t_fdf_info_summary *summary, t_fdf_mapping ***mapping)
{
	t_vars			vars;
	t_graphics_data	img;

	(void) summary;
	(void) mapping;
	
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1280, 720, "Fil De Fer");
	img.img = mlx_new_image(vars.mlx, 1280, 720);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, 2, 1L<<0, fdf_graphics_keypress, &vars);
	mlx_loop(vars.mlx);
}