/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 23:15:37 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/26 15:07:59 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_main_init(t_main *main)
{
	main->file_info.args = NULL;
	main->file_info.args = NULL;
	main->file_info.window_border = 0;
	main->file_info.window_height = 0;
	main->file_info.window_width = 0;
	main->list= NULL;
	main->map.info.height = 0;
	main->map.info.width = 0;
	main->map.info.total = 0;
	main->map.info.zmax = 0;
	main->map.info.zmin = 0;
	main->map.vertices = NULL;
	main->mlx = NULL;
	main->win = NULL;
	main->image.img = NULL;
	main->image.addr = NULL;
	main->image.bits_per_pixel = 0;
	main->image.line_length = 0;
	main->image.endian = 0;
	main->event.color_mode = 0;
	main->event.line_mode = 0;
	main->event.view_mode = 0;
	main->event.scaling = 1;
	main->event.x_angle = 5.934119;
	main->event.z_angle = 0.017453;
	main->event.z_mod = 100;
	main->display = NULL;
}
