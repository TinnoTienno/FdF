/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_push_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:39:59 by eschussl          #+#    #+#             */
/*   Updated: 2024/04/05 00:42:12 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

static t_vertex	fdf_clean_vertex(t_vertex vertex)
{
	vertex.val[1][0] = vertex.val[0][0];
	vertex.val[1][1] = vertex.val[0][1];
	vertex.val[1][2] = vertex.val[0][2];
	return (vertex);
}

static t_vertex	fdf_rotation_vertex(t_main *main, t_vertex vertex)
{
	double	temp_x;
	double	temp_y;

	if (main->event.x_angle)
	{
		temp_y = vertex.val[1][1];
		vertex.val[1][1] = 0 * vertex.val[1][0] + cos(main->event.x_angle * M_PI / 180) * vertex.val[1][1] - sin(main->event.x_angle * M_PI / 180) * vertex.val[1][2];
		vertex.val[1][2] = 0 * vertex.val[1][0] + sin(main->event.x_angle * M_PI / 180) * temp_y + cos(main->event.x_angle * M_PI / 180) * vertex.val[1][2];
	}
	if (main->event.z_angle)
	{
		temp_x = vertex.val[1][0];
		vertex.val[1][0] = 0 * vertex.val[1][2] + cos(main->event.z_angle * M_PI / 180) * vertex.val[1][0] - sin(main->event.z_angle * M_PI / 180) * vertex.val[1][1];
		vertex.val[1][1] = 0 * vertex.val[1][2] + sin(main->event.z_angle * M_PI / 180) * temp_x + cos(main->event.z_angle * M_PI / 180) * vertex.val[1][1];
	}
	return (vertex);
}

static t_vertex	fdf_isometric_vertex(t_main *main, t_vertex vertex)
{
	double	angle1;
	double	angle2;
	double	ax;
	
	angle1 = M_PI / 4;
	angle2 = asin(tan(M_PI / 6));
	if (main->event.viewmode == 0)
	{
		ax = vertex.val[1][0];
		vertex.val[1][0] = cos(angle1) * vertex.val[1][0] - sin(angle1) * vertex.val[1][2];
		vertex.val[1][2] = sin(angle1) * ax + cos(angle1) * vertex.val[1][2];
		vertex.val[1][1] = cos(angle2) * vertex.val[1][1] + sin(angle2) * vertex.val[1][2];
		ax = vertex.val[1][1];
		vertex.val[1][2] = cos(angle2) * vertex.val[1][2] - sin(angle2) * ax;
	}
	return (vertex);
}

static t_vertex	fdf_offsetting(t_main *main, t_vertex vertex)
{
	vertex.val[1][0] = fdf_offsetx(main, fdf_scaling(main, vertex.val[1][0]));
	vertex.val[1][1] = fdf_offsety(main, fdf_scaling(main, vertex.val[1][1]));
	return (vertex);
}


int	fdf_push_loop(t_main *main)
{
	int y;
	int	x;

	y = -1;
	fdf_clean_win(main);
	while (++y < main->minfo.height)
	{
		x = -1;
		while (++x < main->minfo.width)
		{
			main->vertices[y][x] = fdf_clean_vertex(main->vertices[y][x]);
			main->vertices[y][x].val[1][2] = main->vertices[y][x].val[1][2] * (main->event.z_mod) / 100;
			main->vertices[y][x] = fdf_rotation_vertex(main, main->vertices[y][x]);
			main->vertices[y][x] = fdf_isometric_vertex(main, main->vertices[y][x]);
			main->vertices[y][x] = fdf_offsetting(main, main->vertices[y][x]);
			fdf_put_pixel(main, main->vertices[y][x]);
		}
	}
	fdf_lines(main);
	mlx_put_image_to_window(main->mlx, main->win, main->image.img, 0, 0);
	return (1);
}
