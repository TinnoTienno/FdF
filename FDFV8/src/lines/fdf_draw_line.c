/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:31:11 by eschussl          #+#    #+#             */
/*   Updated: 2024/04/05 18:58:48 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

static int	fdf_should_draw(t_main *main, double index, double z1, double z2)
{
	double	z;

	if (main->line.x0 < DEFAULT_WINDOW_BORDER || main->line.y0 \
		< DEFAULT_WINDOW_BORDER || main->line.x0 >= main->finfo.w_width \
		- DEFAULT_WINDOW_BORDER || main->line.y0 >= main->finfo.w_height \
		- DEFAULT_WINDOW_BORDER)
		return (0);
	z = (double) abs((int)(z2 - z1)) * index;
	if (z > main->image_z[main->line.y0][main->line.x0])
	{
		main->image_z[main->line.y0][main->line.x0] = z;
		return (1);
	}
	else
		return (0);
}

t_line	fdf_line_init(t_main *main, t_vertex *v1, t_vertex *v2)
{
	main->line.dy = abs((int)(v2->val[1][1] - v1->val[1][1]));
	main->line.dx = abs((int)(v2->val[1][0] - v1->val[1][0]));
	if (v2->val[1][0] > v1->val[1][0])
		main->line.sx = 1;
	else
		main->line.sx = -1;
	if (v2->val[1][1] > v1->val[1][1])
		main->line.sy = 1;
	else
		main->line.sy = -1;
	main->line.err = main->line.dx - main->line.dy;
	return (main->line);
}

static void	fdf_draw_line_2(t_main *main)
{
	if (main->line.err2 > main->line.dy)
	{
		main->line.err -= main->line.dy;
		main->line.x0 += main->line.sx;
	}
	if (main->line.err2 < main->line.dx)
	{
		main->line.err += main->line.dx;
		main->line.y0 += main->line.sy;
	}
}

void	fdf_draw_line(t_main *main, t_vertex *v1, t_vertex *v2)
{
	int		color;
	double	index;

	main->line = fdf_line_init(main, v1, v2);
	main->line.x0 = v1->val[1][0];
	main->line.y0 = v1->val[1][1];
	while (main->line.x0 != v2->val[1][0] || main->line.y0 != v2->val[1][1])
	{
		if (main->line.dx)
			index = (double)(abs(main->line.x0 - (int) \
				v2->val[1][0])) / (double) main->line.dx;
		else
			index = (double)(abs(main->line.y0 - (int) \
				v2->val[1][1])) / (double) main->line.dy;
		color = fdf_color_shift(index, v2->color[main->event.colormode], \
			v1->color[main->event.colormode]);
		main->line.err2 = 2 * main->line.err;
		fdf_draw_line_2(main);
		if (fdf_should_draw(main, index, v2->val[0][2], v1->val[0][2]) == 1)
			fdf_draw_pixel(main, main->line.x0, main->line.y0, color);
	}
}
