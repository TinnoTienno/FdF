/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_scaling.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:37:09 by eschussl          #+#    #+#             */
/*   Updated: 2024/04/05 18:41:42 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_scaling_first(t_main *main)
{
	double	scale_x;
	double	scale_y;
	int		bwidth;
	int		bheight;

	bwidth = main->finfo.w_width - main->finfo.w_border * 4;
	printf("%d\n", bwidth);
	bheight = main->finfo.w_height - main->finfo.w_border * 4;
	scale_x = bwidth / (double)(main->minfo.xmax - main->minfo.xmin + 1);
	scale_y = bheight / (double)(main->minfo.ymax - main->minfo.ymin + 1);
	if (scale_x < scale_y)
		main->event.scaling = scale_x;
	else
		main->event.scaling = scale_y;
}

int	fdf_scaling(t_main *main, double data)
{
	return (data * main->event.scaling);
}
