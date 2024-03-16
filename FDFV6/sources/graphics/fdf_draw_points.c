/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_points.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:42:52 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/16 15:01:38 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_draw_points(t_main *main)
{
	int i;

	i = 0;
	while (i < main->map->info.width * main->map->info.height)
	{
		//main->map->vertices[i] = (t_map_vertex) { 0};
		my_mlx_pixel_put(&main->image, (int) main->map->vertices[i].x[1], (int) main->map->vertices[i].y[1], main->map->vertices[i].colors[1]);
		printf("%.3f, %d\n", main->map->vertices[i].x[1], (int) round(main->map->vertices[i].x[1]));
		i++;
	}
}