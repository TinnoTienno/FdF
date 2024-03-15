/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_set_points.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:47:34 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/15 22:01:39 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_map_vertex	fdf_scaling(t_main *main, t_map_vertex vertex)
{
	vertex.x[1] = vertex.x[0] * main->scale.indexing;
	vertex.y[1] = vertex.y[0] * main->scale.indexing;
	return (vertex);
}
// static t_map_vertex fdf_translation(t_main *main, t_map_vertex vertex)
// {
// 	(void) main ;
// 	int offset_x;
// 	int offset_y;
	
// 	offset_x = (FDF_WINDOW_WIDTH - main->map->info.width) / 2;
// 	offset_y = (FDF_WINDOW_HEIGHT - main->map->info.height) / 2;

// 	vertex.x[1] = offset_x - vertex.x[1]  ;
// 	vertex.y[1] = offset_y - vertex.y[1];
// 	return (vertex);
// }
static t_map_vertex	fdf_init(t_main *main, t_map_vertex vertex)
{
	(void) main;
	vertex.x[1] = vertex.x[1] + main->scale.window_center_x;
	vertex.y[1] = vertex.y[1] + main->scale.window_center_y;
	vertex.z[1] = vertex.z[1];
	vertex.colors[1] = vertex.colors[0];
	return (vertex);
}
void	fdf_set_points(t_main *main)
{
	int i;

	i = 0;
	while (i < main->map->info.width * main->map->info.height)
	{
		// printf("%.0f, %.0f\n", main->map->vertices[i].x[0],main->map->vertices[i].x[0] + main->scale.window_center_x);
		main->map->vertices[i] = fdf_scaling(main, main->map->vertices[i]);
		main->map->vertices[i] = fdf_init(main, main->map->vertices[i]);
		// main->map->vertices[i] = fdf_translation(main, main->map->vertices[i]);
		// printf("%.0f, %.0f\n", main->map->vertices[i].y[1], main->map->vertices[i].y[1] + main->scale.window_center_y);
		i++;
	}
}