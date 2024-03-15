/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:31:29 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/15 22:58:21 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double ft_abs(double nb)
{
	if (nb < 0)
		nb = - nb;
	return (nb);
}

void my_draw_line(t_map_vertex p0, t_map_vertex p1, t_data *vars)
{
	int dx = ft_abs(p1.x[1] - p0.x[1]);
	int dy = ft_abs(p1.y[1] - p0.y[1]);
	double sx = (p0.x[1] < p1.x[1]) ? 1 : -1;
	double sy = (p0.y[1] < p1.y[1]) ? 1 : -1;
	int err = dx - dy;
	

	while (1)
	{
		my_mlx_pixel_put(vars, p0.x[1], p0.y[1], 0xFFFFFF);
		if (p0.x[1] == p1.x[1] && p0.y[1] == p1.y[1])
			break;

		int e2 = 2 * err;

		if (e2 > -dy)
		{
			err -= dy;
			p0.x[1] += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			p0.y[1] += sy;
		}
	}
}

void	fdf_draw_lines(t_main *main)
{
	int i;

	i = 0;
	while (i < main->map->info.width * main->map->info.height)
	{
		if (i < main->map->info.width * (main->map->info.height - 1))
			my_draw_line(main->map->vertices[i], main->map->vertices[i + main->map->info.height], &main->image);
		if (i % main->map->info.height < main->map->info.width)
			my_draw_line(main->map->vertices[i], main->map->vertices[i + 1], &main->image);
	}
}