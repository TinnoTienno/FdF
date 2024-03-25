/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_scale_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:18:30 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/21 16:38:29 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_scale_init(t_main *main)
{
	double	bwidth;
	double	bheight;
	double	scale_x;
	double	scale_y;
	
	bwidth = main->file_info.window_width - (main->file_info.window_border * 2);
	bheight = main->file_info.window_height - (main->file_info.window_border * 2);
	scale_x = bwidth / (main->map.info.width - 1);
	scale_y = bheight / (main->map.info.height - 1);
	if (scale_x < scale_y)
		main->event.scaling = scale_x;
	else
		main->event.scaling = scale_y;
}