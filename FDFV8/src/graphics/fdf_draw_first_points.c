/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_first_points.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:40:34 by eschussl          #+#    #+#             */
/*   Updated: 2024/04/05 00:24:04 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

static void	fdf_xy_min_max(t_main *main, t_vertex vertex)
{
	if (vertex.val[1][0] < main->minfo.xmin)
		main->minfo.xmin = trunc(vertex.val[1][0]) - 1;
	else if (vertex.val[1][0] > main->minfo.xmax)
		main->minfo.xmax = trunc(vertex.val[1][0]) + 1;
	if (vertex.val[1][1] < main->minfo.ymin)
		main->minfo.ymin = trunc(vertex.val[1][1]) - 1;
	else if (vertex.val[1][1] > main->minfo.ymax)
		main->minfo.ymax = trunc(vertex.val[1][1]) + 1;
}

static t_vertex	fdf_isometric_vertex(t_main *main, t_vertex vertex)
{
	double	angle1;
	double	angle2;
	double	ax;
	
	angle1 = M_PI / 4;
	angle2 = asin(tan(M_PI / 6));
	ax = vertex.val[1][0];
	vertex.val[1][0] = cos(angle1) * vertex.val[1][0] - sin(angle1) * vertex.val[1][2];
	vertex.val[1][2] = sin(angle1) * ax + cos(angle1) * vertex.val[1][2];
	vertex.val[1][1] = cos(angle2) * vertex.val[1][1] + sin(angle2) * vertex.val[1][2];
	ax = vertex.val[1][1];
	vertex.val[1][2] = cos(angle2) * vertex.val[1][2] - sin(angle2) * ax;
	fdf_xy_min_max(main, vertex);
	return (vertex);
}
static t_vertex	fdf_offsetting(t_main *main, t_vertex vertex)
{
	vertex.val[1][0] = fdf_offsetx(main, fdf_scaling(main, vertex.val[1][0]));
	vertex.val[1][1] = fdf_offsety(main, fdf_scaling(main, vertex.val[1][1]));
	return (vertex);	
}

static t_vertex	fdf_clean_vertex(t_vertex vertex)
{
	vertex.val[1][0] = vertex.val[0][0];
	vertex.val[1][1] = vertex.val[0][1];
	vertex.val[1][2] = vertex.val[0][2];
	return (vertex);
}

void	fdf_draw_first_points(t_main *main)
{
	int	y;
	int	x;
	
	y = -1;
	while (++y < main->minfo.height)
	{
		x = -1;
		while (++x < main->minfo.width)
		{
			main->vertices[y][x] = fdf_clean_vertex(main->vertices[y][x]);
			main->vertices[y][x] = fdf_isometric_vertex(main, main->vertices[y][x]);
			fdf_put_pixel(main, main->vertices[y][x]);
		}
	}
	y = -1;
	fdf_scaling_first(main);
	while (++y < main->minfo.height)
	{
		x = -1;
		while (++x < main->minfo.width)
		{
			main->vertices[y][x] = fdf_offsetting(main, main->vertices[y][x]);
		}
	}
	mlx_put_image_to_window(main->mlx, main->win, main->image.img, 0, 0);
}