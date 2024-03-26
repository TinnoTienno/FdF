/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_points.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:42:52 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/26 17:35:09 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_vertex	fdf_isometric_vertex(t_main *main, t_vertex vertex)
{
	if (main->event.view_mode == 0)
	{
		VALUE(vertex, 1, 0) = (VALUE(vertex, 1, 0) - VALUE(vertex, 1, 1)) * cos(M_PI / 6);
		VALUE(vertex, 1, 1) = (VALUE(vertex, 1, 0) + VALUE(vertex, 1, 1)) * sin(M_PI / 6) - VALUE(vertex, 1, 2);
	}
	else
	{
		VALUE(vertex, 1, 0) = VALUE(vertex, 0, 0);
		VALUE(vertex, 1, 1) = VALUE(vertex, 0, 1);
	}
	return (vertex);
}


static t_vertex	fdf_rotation_vertex(t_main *main, t_vertex vertex)
{
	double	temp_x;
	double	temp_y;

	if (main->event.x_angle)
	{
		temp_y = VALUE(vertex, 1, 1);
		VALUE(vertex, 1, 1) = 0 * VALUE(vertex, 1, 0) + cos(main->event.x_angle) * VALUE(vertex, 1, 1) - sin(main->event.x_angle) * VALUE(vertex, 1, 2);
		VALUE(vertex, 1, 2) = 0 * VALUE(vertex, 1, 0) + sin(main->event.x_angle) * temp_y + cos(main->event.x_angle) * VALUE(vertex, 1, 2);
	}
	if (main->event.z_angle)
	{
		temp_x = VALUE(vertex, 1, 0);
		VALUE(vertex, 1, 0) = 0 * VALUE(vertex, 1, 2) + cos(main->event.z_angle) * VALUE(vertex, 1, 0) - sin(main->event.z_angle) * VALUE(vertex, 1, 1);
		VALUE(vertex, 1, 1) = 0 * VALUE(vertex, 1, 2) + sin(main->event.z_angle) * temp_x + cos(main->event.z_angle) * VALUE(vertex, 1, 1);
	}
	return (vertex);
}
static t_vertex	fdf_clean_vertex(t_vertex vertex)
{
	VALUE(vertex, 1, 0) = VALUE(vertex, 0, 0);
	VALUE(vertex, 1, 1) = VALUE(vertex, 0, 1);
	VALUE(vertex, 1, 2) = VALUE(vertex, 0, 2);
	return (vertex);
}
static t_vertex	fdf_alt_mod_vertex(t_main *main, t_vertex vertex)
{
	VALUE(vertex, 1, 2) = VALUE(vertex, 1, 2) * (main->event.z_mod) / 100;
	return (vertex);
}

static t_vertex	fdf_offsetting(t_main *main, t_vertex vertex)
{
	VALUE(vertex, 1, 0) = fdf_offsetx(main, fdf_scaling(main, VALUE(vertex, 1, 0)));
	VALUE(vertex, 1, 1) = fdf_offsety(main, fdf_scaling(main, VALUE(vertex, 1, 1)));
	return (vertex);
}

void	fdf_draw_points(t_main *main)
{
	int y;
	int	x;

	y = -1;
	fdf_image_z_clean(main);
	while (++y < main->map.info.height)
	{
		x = -1;
		while (++x < main->map.info.width)
		{
			VERTEX(x, y) = fdf_clean_vertex(VERTEX(x, y));
			VERTEX(x, y) = fdf_alt_mod_vertex(main, VERTEX(x, y));
			VERTEX(x, y).colormod = fdf_color2_vertex(main, VERTEX(x, y));
			VERTEX(x, y) = fdf_rotation_vertex(main, VERTEX(x, y));
			VERTEX(x, y) = fdf_isometric_vertex(main, VERTEX(x, y));
			VERTEX(x, y) = fdf_offsetting(main, VERTEX(x, y));
			if (fdf_should_draw(main, VERTEX(x, y)) == 1)
				fdf_draw_vertex(main, VERTEX(x, y));
		}
	}
	mlx_put_image_to_window(main->mlx, main->win, main->image.img, 0, 0);
}
