/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_image_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:48:15 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/21 15:37:11 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_image_init(t_main *main)
{
	main->image.img = mlx_new_image(main->mlx, main->file_info.window_width, main->file_info.window_height);

	main->image.center_x = main->file_info.window_width / 2;
	main->image.center_y = main->file_info.window_height / 2;
	if (!main->image.img)
		fdf_error(main, "Error in mlx_new_image function : Malloc\n");
	main->image.addr = mlx_get_data_addr(main->image.img, &main->image.bits_per_pixel, &main->image.line_length, &main->image.endian);
	mlx_put_image_to_window(main->mlx, main->win, main->image.img, 0, 0);
}