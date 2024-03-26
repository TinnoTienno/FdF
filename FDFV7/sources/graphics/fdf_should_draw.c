/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_should_draw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:46:38 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/26 17:46:29 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_should_draw(t_main *main, t_vertex vertex)
{
	int	x;
	int	y;

	x = vertex.values[1][0];
	y = vertex.values[1][1];
	if (x < DEFAULT_WINDOW_BORDER || y < DEFAULT_WINDOW_BORDER || x >= main->file_info.window_width - DEFAULT_WINDOW_BORDER || y >= main->file_info.window_height - DEFAULT_WINDOW_BORDER)
		return (0);
	if (main->image_z[y][x] == -999999999)
		return (1);
	if (main->event.x_angle >= 180 * (M_PI /180))
	{
		if (vertex.values[1][2] < main->image_z[y][x])
			return (0);
	}
	else
	{
		if (vertex.values[1][2] > main->image_z[y][x])
			return (0);
	}
	return (1);
}