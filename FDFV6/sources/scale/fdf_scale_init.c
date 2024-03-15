/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_scale_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:06:55 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/15 19:43:44 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_scale fdf_scale_init(t_main *main)
{
	t_scale scale;

	scale.bwidth = FDF_WINDOW_WIDTH - (FDF_WINDOW_BORDER * 2);
	scale.bheight = FDF_WINDOW_HEIGHT - (FDF_WINDOW_BORDER * 2);
	scale.window_center_x = (FDF_WINDOW_WIDTH - 1) / 2;
	scale.window_center_y = (FDF_WINDOW_HEIGHT - 1) / 2;
	// printf("bheight ; %d\n", scale.bheight);
	scale.scale_x = (double) scale.bwidth / ((double) main->map->info.width - 1);
	scale.scale_y = (double) scale.bheight / ((double) main->map->info.height - 1);
	// printf("scale_y : %f\n", scale.scale_y);
	if (scale.scale_x < scale.scale_y)
		scale.indexing = scale.scale_x;
	else
		scale.indexing = scale.scale_y;
	// printf("scale.indexing = %f\n", scale.indexing);
	return (scale);
}