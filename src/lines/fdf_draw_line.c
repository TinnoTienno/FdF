/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:31:11 by eschussl          #+#    #+#             */
/*   Updated: 2024/04/10 15:57:52 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

static int	fdf_should_draw(t_main *main, double index, double z1, double z2, t_line *line)
{
	double	z;

	if (line->x0 < DEFAULT_WINDOW_BORDER || line->y0 \
		< DEFAULT_WINDOW_BORDER || line->x0 >= main->finfo.w_width \
		- DEFAULT_WINDOW_BORDER || line->y0 >= main->finfo.w_height \
		- DEFAULT_WINDOW_BORDER)
		return (0);
	if (z2 > z1)
		z = (double)(int)(z2 - z1) *index;
	else
		z = (double)(int)(z1 - z2) *index;
	if (z > main->image_z[line->y0][line->x0])
	{
		main->image_z[line->y0][line->x0] = z;
		return (1);
	}
	else
		return (0);
}

t_line	fdf_line_init(t_vertex *v1, t_vertex *v2)
{
    t_line line;

	line.dy = abs((int)(v2->val[1][1] - v1->val[1][1]));
	line.dx = abs((int)(v2->val[1][0] - v1->val[1][0]));
	if (v2->val[1][0] > v1->val[1][0])
		line.sx = 1;
	else
		line.sx = -1;
	if (v2->val[1][1] > v1->val[1][1])
		line.sy = 1;
	else
		line.sy = -1;
	line.err = line.dx - line.dy;
	return (line);
}

void	fdf_draw_line_2(t_line *line)
{
	line->err2 = line->err * 2;
	if (line->err2 > -line->dy)
	{
		line->err -= line->dy;
		line->x0 += line->sx;
	}
	if (line->err2 < line->dx)
	{
		line->err += line->dx;
		line->y0 += line->sy;
	}
}

void	fdf_draw_line(t_main *main, t_vertex *v1, t_vertex *v2)
{
	int		color;
	double	index;

	if (fdf_line_oob(main, v1, v2) != 0)
		return ;
	t_line		line = fdf_line_init(v1, v2);
	line.x0 = v1->val[1][0];
	line.y0 = v1->val[1][1];
	while (line.x0 != v2->val[1][0] || line.y0 != v2->val[1][1])
	{
		if (line.dx)
			index = (double)(abs(line.x0 - (int) \
				v2->val[1][0])) / (double) line.dx;
		else
			index = (double)(abs(line.y0 - (int) \
				v2->val[1][1])) / (double) line.dy;
		fdf_draw_line_2(&line);
		if (fdf_should_draw(main, index, v1->val[0][2], v2->val[0][2], &line) == 1)
		{
			color = fdf_color_shift(index, v2->color[main->event.colormode], \
			v1->color[main->event.colormode]);
			fdf_draw_pixel(main, line.x0, line.y0, color);
		}
	}
}
