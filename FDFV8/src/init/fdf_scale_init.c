/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_scale_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:27:08 by eschussl          #+#    #+#             */
/*   Updated: 2024/04/04 22:50:07 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	fdf_scale_init(t_main *main)
{
	double	bwidth;
	double	bheight;
	double	scale_x;
	double	scale_y;
	t_finfo	finfo;

	finfo = main->finfo;
	main->event.z_mod = 100;
	main->event.x_angle = 90;
	bwidth = finfo.w_width - finfo.w_border * 2;
	bheight = finfo.w_height - finfo.w_border * 2;
	scale_x = bwidth / (main->minfo.width - 1);
	scale_y = bheight / (main->minfo.height - 1);
	if (scale_x < scale_y)
		main->event.scaling = scale_x;
	else
		main->event.scaling = scale_y;
	main->minfo.xmax = -2147483648;
	main->minfo.ymax = -2147483648;
	main->minfo.xmin = 2147483647;
	main->minfo.ymin = 2147483647;
}
