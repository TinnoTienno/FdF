/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_points.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:42:52 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/25 13:59:20 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_draw_points(t_main *main)
{
	int y;
	int	x;

	y = 0;
	if (main->event.color_mode == 0)
	{
		while (y < main->map.info.height)
		{
			x = -1;
			while (++x < main->map.info.width)
			{
				my_mlx_pixel_put(main, fdf_offsetx(main, fdf_scaling(main, main->map.vertices[y][x].values[1][0])), fdf_offsety(main, fdf_scaling(main, main->map.vertices[y][x].values[1][1])), main->map.vertices[y][x].color);
			}
			y++;
		}
	}
	else
	{
		while (y < main->map.info.height)
		{
			x = -1;
			while (++x < main->map.info.width)
				my_mlx_pixel_put(main, fdf_offsetx(main, fdf_scaling(main, main->map.vertices[y][x].values[1][0])), fdf_offsety(main, fdf_scaling(main, main->map.vertices[y][x].values[1][1])), fdf_color2_vertex(main->map.vertices[y][x].values[0][2], main));
			y++;
		}
	}
	mlx_put_image_to_window(main->mlx, main->win, main->image.img, 0, 0);
}