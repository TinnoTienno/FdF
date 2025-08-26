/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_image_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:10:34 by eschussl          #+#    #+#             */
/*   Updated: 2024/04/05 19:42:14 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_image_init(t_main *main)
{
	main->image.img = mlx_new_image(main->mlx, \
		main->finfo.w_width, main->finfo.w_height);
	main->image.center_x = main->finfo.w_width / 2;
	main->image.center_y = main->finfo.w_height / 2;
	if (!main->image.img)
		fdf_error(main, "Error in mlx_new_image function : Malloc\n");
	main->image.addr = mlx_get_data_addr(main->image.img, \
		&main->image.bits_per_pixel, &main->image.line_length, \
			&main->image.endian);
	fdf_draw_first_points(main);
	mlx_put_image_to_window(main->mlx, main->win, main->image.img, 0, 0);
}
